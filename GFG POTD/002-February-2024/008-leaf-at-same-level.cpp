// https://www.geeksforgeeks.org/problems/leaf-at-same-level/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  private:
    // TC : O(N) because each node is visited once
    // SC : O(N) At worst, queue can hold all the nodes of the tree (when the tree is a complete binary tree)
    bool solve_approach_1(Node* root) {
        if (!root) return true;
    
        queue<pair<Node* , int>> q;
        q.push({root, 0});
        int same = -1;
        
        while(!q.empty()) {
            
            // process each level separately
            int size = q.size();
            while (size --) {
                Node* fNode = q.front().first;
                int crLevel = q.front().second;
                q.pop();
                
                if (!fNode -> left && !fNode -> right) {
                    if (same == -1) same = crLevel;
                    else if (same != crLevel) {
                        return false;
                    }
                }
                
                if(fNode -> left ) q.push({fNode -> left , crLevel + 1});
                if(fNode -> right) q.push({fNode -> right, crLevel + 1});
            }
        }
        
        return true;
    }
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        return solve_approach_1(root);
    }
};

//{ Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin>> t;
    getchar();
    while (t--)
    {
        string s;
        getline( cin, s );
        Node* head = buildTree( s );
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends