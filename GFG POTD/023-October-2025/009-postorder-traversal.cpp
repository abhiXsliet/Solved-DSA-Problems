// https://www.geeksforgeeks.org/problems/postorder-traversal/1/




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
  private:
    void solve(Node* root, vector<int> &result) {
        if (!root) return;
        
        solve(root -> left, result);
        solve(root ->right, result);
        result.push_back(root -> data);
    }
  public:
    // TC : O(N)
    // SC : O(1)
    vector<int> postOrder(Node* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
};