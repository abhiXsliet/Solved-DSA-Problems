// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
// } Driver Code Ends

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    void getLeftBoundary(Node *root, vector<int> &res) {
        if (!root || (!root -> left && !root -> right))
            return;
            
        res.push_back(root -> data);
        
        if (root -> left)
            getLeftBoundary(root -> left, res);
        else 
            getLeftBoundary(root -> right, res);
    }
    
    void getLeafNodes(Node *root, vector<int> &res) {
        if (!root) return;
        if (!root -> left && !root -> right) {
            res.push_back(root -> data);
            return;
        }
        getLeafNodes(root -> left, res);
        getLeafNodes(root ->right, res);
    }
    
    void getRightBoundary(Node *root, vector<int> &res) {
        if (!root || (!root -> left && !root -> right))
            return;
        
        if (root -> right)
            getRightBoundary(root -> right, res);
        else 
            getRightBoundary(root -> left , res);
            
        res.push_back(root -> data);
    }
  public:
    // TC : O(N)
    // SC : O(1)
    vector<int> boundaryTraversal(Node *root) {
        vector<int> result;
        if (!root) return result;
        if (root -> left || root -> right)
            result.push_back(root -> data);
            
        getLeftBoundary(root -> left, result);      // get all the left boundary nodes excluding leaves
        getLeafNodes(root, result);                 // get all the leaf nodes
        getRightBoundary(root -> right, result);    // get all the right boundary nodes excluding leaves
        return result;
    }
};


//{ Driver Code Starts.
/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends