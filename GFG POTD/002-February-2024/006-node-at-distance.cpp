// https://www.geeksforgeeks.org/problems/node-at-distance/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    private:
    // TC : O(N)
    // SC : O(H)
    void solve_1(Node* root, vector<vector<Node*>>& paths, vector<Node*>& temp) {
        if (!root) return;
        
        temp.push_back(root);
        
        solve_1(root -> left , paths, temp);
        solve_1(root -> right, paths, temp);
        
        if (!root -> left && !root -> right) {
            paths.push_back(temp);
        }
        
        temp.pop_back();
    }
    
    // TC : O(N)
    // SC : O(N/2 * h) ~= O(N*H)
    int solve_approach_1(Node* root, int k) {
        vector<vector<Node*>> paths;
        vector<Node*> temp;
        
        solve_1(root, paths, temp);
        
        unordered_set<Node*> uniqueNode;
        
        for (auto& path : paths) {
            int n = path.size();
            if (n > k) {
                int idx = n - k - 1;
                uniqueNode.insert(path[idx]);
            }
        }
        
        return uniqueNode.size();
    }
    
    // TC : O(N)
    // SC : O(H) -> temp could end up storing nodes till the height of tree
    void solve_2(Node* root, int k, int idx, vector<Node*>& temp, unordered_set<Node*>& st) {
        if (!root) return;
        
        temp.push_back(root);
        
        solve_2(root -> left , k, idx + 1, temp, st);
        solve_2(root -> right, k, idx + 1, temp, st);
        
        if (!root -> left && !root -> right) {
            if (idx >= k) {
                st.insert(temp[idx - k]);
            }
        }
        
        temp.pop_back();
    }
    
    // TC : O(N)
    // SC : O(H)
    int solve_approach_2(Node* root, int k) {
        vector<Node*> temp;
        unordered_set<Node*> st;
        
        solve_2(root, k, 0, temp, st);
        
        return st.size();
    }
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
        // return solve_approach_1(root, k);
        
        return solve_approach_2(root, k);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends