// https://www.geeksforgeeks.org/problems/largest-bst/1/




#include <bits/stdc++.h>
using namespace std;

/* Tree node structure  used in the program*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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