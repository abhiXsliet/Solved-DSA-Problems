// https://www.geeksforgeeks.org/problems/check-for-bst/1




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
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(H)
    bool approach_1(Node *root, int mini, int maxi) {
        if (!root) return true;
        
        if (root -> data < mini || root -> data > maxi)
            return false;
            
        return approach_1(root ->  left, mini, root -> data - 1) &&
               approach_1(root -> right, root -> data + 1, maxi);
    }
    
    // TC : O(N)
    // SC : O(H) Due to recursive call stack
    bool approach_2(Node *root, int &prev) {
        if (!root) return true;
        
        if (!approach_2(root -> left, prev))
            return false;
        
        if (prev >= root -> data)
            return false;
        
        prev = root -> data;
            
        return approach_2(root -> right, prev);
    }
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // return approach_1(root, INT_MIN, INT_MAX);   // Track Range in left and right subtree
        int prev = INT_MIN;
        return approach_2(root, prev);            // Using Inorder if not sorted then false
    }
};


//{ Driver Code Starts.
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

    // Create the root of the tree
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

void inorder(Node* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        // if (s[0] == '9') {
        //     cout << "false\n";
        //     return 0;
        // }
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "true\n";

        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends