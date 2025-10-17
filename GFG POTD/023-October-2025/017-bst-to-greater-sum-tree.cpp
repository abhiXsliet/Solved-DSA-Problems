// https://www.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1/




#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  private:
    void solve(Node *root, int &sum) {
        if (!root) return;
        
        solve(root -> right, sum);
        
        int temp = root -> data;
        root -> data = sum;
        sum += temp;
        
        solve(root -> left, sum);
    }
  public:
    // TC : O(N)
    // SC : O(1)
    void transformTree(Node *root) {
        int sum = 0;
        solve(root, sum);
    }
};