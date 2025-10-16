// https://www.geeksforgeeks.org/problems/remove-bst-keys-outside-given-range/1/




#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        
        // Case 1: root ka value l se chhota hai → left subtree discard
        if (root->data < l)
            return removekeys(root->right, l, r);
        
        // Case 2: root ka value r se bada hai → right subtree discard
        if (root->data > r)
            return removekeys(root->left, l, r);
        
        // Case 3: root valid hai → left/right subtree recursively prune
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        
        return root;
    }
};