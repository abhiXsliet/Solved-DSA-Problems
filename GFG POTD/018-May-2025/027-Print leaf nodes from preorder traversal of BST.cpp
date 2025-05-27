// https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    struct Node {
        int data;
        Node *left, *right;
        Node(int data) {
            this -> data  = data;
            this -> left  = NULL;
            this -> right = NULL;
        }
    };
    
    // TC : O(N)
    // SC : O(N) 
    Node* generateTree(vector<int> &preorder, vector<int> &result, int &idx, int maxi, int mini) {
        if (idx >= preorder.size()) return NULL;
        
        int val = preorder[idx];
        if (val >= maxi || val <= mini) return NULL;
        
        Node *root = new Node(val);
        idx ++;
        
        root -> left  = generateTree(preorder, result, idx, root -> data, mini);
        root -> right = generateTree(preorder, result, idx, maxi, root -> data);
        
        if (!root -> left && !root -> right) 
        result.push_back(root -> data);
        
        return root;
    }
    public:
    vector<int> leafNodes(vector<int>& preorder) {
        // Brute   : O(N^2) to build the tree by checking each node to be placed to not violate the bst property, O(N) is the space for the tree
        // Better  : Generate Tree using preorder and inorder traversal (sort preorder to get inorder), tc : O(NlogN) and sc : O(N)
        // Optimal : Track ranges for each node to build the tree, so tc : O(N) and sc : O(N)
        
        vector<int> result;
        int idx = 0;
        generateTree(preorder, result, idx, INT_MAX, INT_MIN);
        return result;
    }
};