// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    // TC : O(N) N = Total No. of Nodes in BST
    // SC : O(H) Height of BST
    void solve(Node* root, vector<int>& res) {
        if (!root) return;
        
        solve(root -> left, res);
        res.push_back(root -> data);
        solve(root -> right, res);
    }
    
    // TC : O((M + N) * log(M + N))
    // SC : O(M + N)
    vector<int> approach_1(Node* r1, Node* r2) {
        vector<int> result;
        solve(r1, result);
        solve(r2, result);
        sort(begin(result), end(result));
        return result;
    }
    
    // TC : O(M + N)
    // SC : O(M + N)
    vector<int> approach_2(Node* r1, Node* r2) {
        vector<int> store1;
        vector<int> store2;
        solve(r1, store1);
        solve(r2, store2);
        
        vector<int> result;
        int i = 0, j = 0;
        while (i < store1.size() && j < store2.size()) {
            if (store1[i] <= store2[j]) {
                result.push_back(store1[i ++]);
            } else {
                result.push_back(store2[j ++]);
            }
        }
        while (i < store1.size()) {
            result.push_back(store1[i ++]);
        }
        while (j < store2.size()) {
            result.push_back(store2[j ++]);
        }
        return result;
    }
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // return approach_1(root1, root2);    // store and sort 
        
        return approach_2(root1, root2);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends