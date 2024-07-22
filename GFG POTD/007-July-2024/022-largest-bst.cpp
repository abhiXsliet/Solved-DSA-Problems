// https://www.geeksforgeeks.org/problems/largest-bst/1




//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeStructure {
public:
    int maxi, mini, size;
    NodeStructure(int min, int max, int s) {
        this -> maxi = max;
        this -> mini = min;
        this -> size = s;
    }
};

class Solution{
    private:
    bool isValidBst(Node* root, int mini, int maxi) {
        if (!root) return 1;
        
        if (root -> data > mini && root -> data < maxi) {
            return (isValidBst(root -> left , mini, root -> data) &&
                    isValidBst(root -> right, root -> data, maxi));
        }
        return 0;
    }
    
    int getCountOfNodes(Node* root) {
        if (!root) return 0;
        return 1 + getCountOfNodes(root -> left) + getCountOfNodes(root -> right);
    }
    
    // TC : O(N*N)
    // SC : O(N) -> Depth of Recursion
    int brute(Node* root) {
        if (!root) return 0;
        
        if (isValidBst(root, INT_MIN, INT_MAX)) {
            // If curr node is validBst then get size of entire subtree 
            return getCountOfNodes(root);
            
        } else {
            return max(brute(root -> left),  brute(root -> right));
        }
    }
    
    // TC : O(N)
    // SC : O(1) 
    NodeStructure optimal(Node* root) {
        if (!root) return NodeStructure(INT_MAX, INT_MIN, 0);
        
        // Post-Order Traversal : LRN
        NodeStructure L = optimal(root -> left );
        NodeStructure R = optimal(root -> right);
        
        if (L.maxi < root -> data && root -> data < R.mini) {
            return NodeStructure(min(root -> data, L.mini), 
                                 max(root -> data, R.maxi), 
                                 1 + L.size + R.size);
        }
        
        // else : return [-inf, inf] so, that parent can't be a valid BST
        return NodeStructure(INT_MIN, INT_MAX, max(L.size, R.size));
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	// return brute(root);
        
        return optimal(root).size;
    }
};

//{ Driver Code Starts.
/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
// } Driver Code Ends