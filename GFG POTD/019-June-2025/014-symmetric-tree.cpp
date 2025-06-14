// https://www.geeksforgeeks.org/problems/symmetric-tree/1




#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  private:
    bool isMirror(Node* r1, Node* r2) {
        if (!r1 || !r2) 
            return (!r1 && !r2);
        
        if (r1 -> data != r2 -> data) 
            return false;
        
        return (isMirror(r1 -> left, r2 -> right) && isMirror(r1 -> right, r2 -> left));
    }
  public:
    // TC : O(N)
    // SC : O(H) where H is the height of the tree
    bool isSymmetric(Node* root) {
        if (!root) return true;
        return (isMirror(root -> left, root -> right));
    }
};