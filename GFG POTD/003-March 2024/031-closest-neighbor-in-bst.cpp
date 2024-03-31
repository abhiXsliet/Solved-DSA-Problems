// https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->key = val;
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
// User function Template for C++
/*
//Structure of the Node of the BST is as
struct Node {
    int key;
    Node* left, *right;
};


   'N' is the element
   'size' is the total element in BST
  */

class Solution {
  private:
    // TC : O(H)
    // SC : O(1)
    int solve_1(Node* root, int n) {
        Node* temp = NULL;
        while(root) {
            if (root -> key <= n) {
                temp = root;
                root = root -> right;
            }
            else {
                root = root -> left;
            }
        }
        return temp ? temp -> key : -1;
    }
    
    // TC : O(H)
    // SC : O(1)
    int solve_2(Node* root, int n) {
        int ans = -1;
        while(root) {
            if (root -> key == n) {
                return root -> key;
            }
            else if (root -> key < n) {
                ans = root -> key;
                root = root -> right;
            }
            else {
                root = root -> left;
            }
        }
        return ans;
    }
  public:
    int findMaxForN(Node* root, int n) {
        // return solve_1(root, n);
        
        return solve_2(root, n);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int x;
        cin >> x;

        Node* root = buildTree(s);
        Solution ob;
        cout << ob.findMaxForN(root, x) << endl;
    }
    return 1;
}

// } Driver Code Ends