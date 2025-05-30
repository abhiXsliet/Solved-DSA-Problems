// https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1




#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
    void dfs(Node *root, int k, int &result) {
        if (!root) return;
        
        if (root -> data > result && root -> data <= k)
            result = root -> data;
            
        dfs(root ->  left, k, result);
        dfs(root -> right, k, result);
    }
  public:
    // TC : O(N)
    // SC : O(H)
    int approach_1(Node *root, int k) {
        int result = -1;
        dfs(root, k, result);
        return result;
    }
    
    // TC : O(H)
    // SC : O(H)
    int approach_2(Node *root, int k) {
        int ans = -1;
        while (root) {
            if (root -> data <= k) {
                ans = root -> data;
                root = root -> right;
            } else {
                root = root -> left;
            }
        }
        return ans;
    }
    int findMaxFork(Node* root, int k) {
        // return approach_1(root, k);
        return approach_2(root, k);     // use bst prop.
    }
};