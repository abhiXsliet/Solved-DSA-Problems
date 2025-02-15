// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
    // TC : O(H)
    // SC : O(H)
    bool exists(Node *root, Node *n) {
        if (!root) 
            return false;
            
        if (root -> data == n -> data)
            return true;
        
        return root -> data > n -> data ? exists(root -> left, n) : exists(root -> right, n);
    }
    
    // TC : O(N)
    // SC : O(H)
    // this fn is not optimal for bst since it iterating on every nodes
    bool checkIfExist(Node *root, Node *n) {
        if (!root) return false;
        
        if (root -> data == n -> data)
            return true;
            
        if (checkIfExist(root -> left, n) || checkIfExist(root -> right, n))
            return true;
            
        return false;
    }
    
    // TC : O(N)
    // SC : O(H)
    // Function to get the path from root to node `n`
    bool getPath(Node* root, Node* n, vector<Node*>& path) {
        if (!root) return false;
        
        path.push_back(root);
        if (root -> data == n -> data) 
            return true;
        
        if (getPath(root ->  left, n, path) || getPath(root -> right, n, path)) 
            return true;
        
        path.pop_back();
        return false;
    }
    
    // TC : O(N)
    // SC : O(N)
    Node* approach_1(Node *root, Node *n1, Node *n2) {
        vector<Node*> path1, path2;
        
        getPath(root, n1, path1);
        getPath(root, n2, path2);
        
        if (path1.empty() || path2.empty()) return NULL;
        
        int i = 0, j = 0;
        while (i < path1.size() && j < path2.size()) {
            if (path1[i] != path2[j])
                return path1[i - 1];    // {15, 8, 7}, {15, 8, 6} => LCA = 8
            i ++, j ++;
        }
        
        return path1[i - 1];    // since both nodes are available in tree
    }
    
    // TC : O(N)
    // SC : O(H)
    Node* approach_2(Node *root, Node *n1, Node *n2) {
        if (!root) return NULL;
        
        if (root -> data == n1 -> data || root -> data == n2 -> data)
            return root;
            
        Node* L = approach_2(root ->  left, n1, n2);
        Node* R = approach_2(root -> right, n1, n2);
        
        // one data is present in one subtree and the other is present in the other, so this node is the LCA
        if (L && R) return root;
        
        // one of the node is not null means that node is LCA
        return !L ? R : L;
    }
    
    // TC : O(N)
    // SC : O(H)
    Node* approach_3(Node *root, Node *n1, Node *n2) {
        if (!checkIfExist(root, n1) || !checkIfExist(root, n2))
            return NULL;
        
        return approach_2(root, n1, n2);
    }
    
    // TC : O(H)
    // SC : O(H)
    Node* approach_4(Node *root, Node *n1, Node *n2) {
        if (!root) return NULL;
        
        // root is greater than both of the nodes, so go to left 
        if (root -> data > n1 -> data && root -> data > n2 -> data) {
            return approach_4(root -> left, n1, n2);
        } // root is greater than both of the nodes, so go to left
        else if (root -> data < n1 -> data && root -> data < n2 -> data) {
            return approach_4(root -> right, n1, n2);
        }
        
        // else one node lies in left and other node lies in right subtree
        return root;
    }
    
    // TC : O(H)
    // SC : O(1)
    Node* approach_5(Node *root, Node *n1, Node *n2) {
        while (root) {
            if (root -> data > n1 -> data && root -> data > n2 -> data) {
                root = root -> left;
            } else if (root -> data < n1 -> data && root -> data < n2 -> data) {
                root = root -> right;
            } else break;
        }
        return root;
    }
    
    // TC : O(H)
    // SC : O(1)
    Node* approach_6(Node *root, Node *n1, Node *n2) {
        if (!exists(root, n1) || !exists(root, n2))
            return NULL;
            
        // return approach_4(root, n1, n2);
        return approach_5(root, n1, n2);
    }
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // return approach_1(root, n1, n2);    // This approach stores the paths of both nodes in separate arrays and returns the last common node by simultaneously traversing both paths.
        
        // return approach_2(root, n1, n2);    // This approach works, but it fails if either of the nodes is absent in the tree, as it assumes both nodes are present.
        
        // return approach_3(root, n1, n2);    // This approach handles cases where one or both nodes might be absent and still works correctly.
        

        // -------- All of the above approaches are primarily designed for binary trees, but they can also be applied to binary search trees (BSTs).
        
        // return approach_4(root, n1, n2);     // This approach uses BST property : Recursive Way (doesn't works if one of the node is absent from tree, to overcome it check in prior for existence of node) 
       
        // return approach_5(root, n1, n2);     // This approach uses BST property : Iterative Way (doesn't works if one of the node is absent from tree, to overcome it check in prior for existence of node)
        
        return approach_6(root, n1, n2);     // This approach uses BST property : Iterative Way (checked in prior for existence of node)
    }
};


//{ Driver Code Starts.
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

Node* searchOnTree(Node* root, int num) {
    if (root == nullptr || root->data == num)
        return root;
    if (num < root->data)
        return searchOnTree(root->left, num);
    else
        return searchOnTree(root->right, num);
}

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node* root = buildTree(s);
        Node* n1 = searchOnTree(root, l);
        Node* n2 = searchOnTree(root, h);
        Solution sol;
        int ans = sol.LCA(root, n1, n2)->data;
        cout << ans << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends