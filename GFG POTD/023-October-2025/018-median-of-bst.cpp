// https://www.geeksforgeeks.org/problems/median-of-bst/1/




#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class Solution {
    private:
    void func(Node *root, int &cntNodes) {
        if (!root) return;
        
        cntNodes += 1;
        func(root ->  left, cntNodes);
        func(root -> right, cntNodes);
    }
    
    int solve(Node *root, int &n) {
        if (!root) return INT_MIN;
        
        int left = solve(root -> left, n);
        
        n --;
        if (n == 0) return root -> data;
        
        int right = solve(root -> right, n);
        
        return max(left, right);
    }
    public:
    // TC : O(N)
    // SC : O(1)
    int findMedian(Node* root) {
        int cntNodes = 0;
        func(root, cntNodes);
        
        if (cntNodes % 2) {
            int n = ((cntNodes + 1) / 2);
            return solve(root, n);
        } 
        int n = (cntNodes / 2);
        return solve(root, n);
    }
};