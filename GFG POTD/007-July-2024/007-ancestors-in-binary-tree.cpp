// https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
// User function template for C++
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
  private:
    bool solve(Node* root, int tar, vector<int>& result) {
        if (!root) return false;

        if (root->data == tar) {
            // Found the target node, no need to continue searching
            return true;
        }

        // Check if the target node is an ancestor in the left subtree
        bool foundInLeft = solve(root->left, tar, result);
        if (foundInLeft) {
            result.push_back(root->data);
            return true;
        }

        // Check if the target node is an ancestor in the right subtree
        bool foundInRight = solve(root->right, tar, result);
        if (foundInRight) {
            result.push_back(root->data);
            return true;
        }

        return false;
    }
    
    void func(Node* root, int tar, vector<int>& store, vector<int>& result) {
        if (!root) return;

        if (root -> data == tar) {
            result = store;
            return;
        }
        
        store.push_back(root -> data);
        func(root -> left , tar, store, result);
        func(root -> right, tar, store, result);
        store.pop_back();
    }
    
    // TC : O(N)
    // SC : O(H)
    vector<int> approach_1(Node* root, int target) {
        vector<int> result;
        solve(root, target, result);
        return result;
    }
    
    // TC : O(N)
    // SC : O(H)
    vector<int> approach_2(Node* root, int target) {
        vector<int> temp;
        vector<int> result;
        func(root, target, temp, result);
        reverse(begin(result), end(result));
        return result;
    }
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        // return approach_1(root, target);
        
        return approach_2(root, target);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);

        int target;
        cin >> target;
        getchar();

        Node* root = buildTree(s);
        Solution obj;
        vector<int> nodes = obj.Ancestors(root, target);
        for (int i = 0; i < nodes.size(); i++) {
            cout << nodes[i] << " ";
        }
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends