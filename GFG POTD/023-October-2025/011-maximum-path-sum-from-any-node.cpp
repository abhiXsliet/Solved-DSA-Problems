// https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/




#include <bits/stdc++.h>
using namespace std;

// User Fuction template for C++
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  private:
    int solve(Node *root, int &maxSum) {
        if (!root) return 0;
        
        int L = solve(root -> left , maxSum);
        int R = solve(root -> right, maxSum);
        
        int op1 = L + R + root -> data;
        int op2 = max(L, R) + root -> data;
        int op3 = root -> data;
        
        maxSum = max(maxSum, max({op1, op2, op3}));
        
        return max({op2, op3});
    }
  public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};