// https://www.geeksforgeeks.org/problems/range-sum-of-bst/1/




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

class Solution {
  private:
    void solve(Node *root, int &sum, int l, int r) {
        if (!root) return;
        
        if (root -> data >= l && root -> data <= r) 
            sum += root -> data;
        
        solve(root ->  left, sum, l, r);
        solve(root -> right, sum, l, r);
    }
  public:
    int nodeSum(Node* root, int l, int r) {
        int sum = 0;
        solve(root, sum, l, r);
        return sum;
    }
};