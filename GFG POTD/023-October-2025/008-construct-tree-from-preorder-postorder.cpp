// https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-postorder/1/




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
    Node *solve(vector<int> &pre, vector<int> &post, unordered_map<int, int> &mpp, int &preIdx, int posSt, int posEnd) {
        if (posSt > posEnd) {
            return NULL;
        }
        
        Node *root = new Node(pre[preIdx ++]);
        if (posSt == posEnd) return root;
        
        int pos = mpp[pre[preIdx]];
        
        root ->  left = solve(pre, post, mpp, preIdx, posSt, pos);
        root -> right = solve(pre, post, mpp, preIdx, pos + 1, posEnd - 1);
        
        return root;
    }
  public:
    // TC : O(N)
    // SC : O(N)
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        unordered_map<int, int> mpp;    // postIndexMap
        for (int i = 0; i < n; i ++) mpp[post[i]] = i;
        
        int preIdx = 0;
        return solve(pre, post, mpp, preIdx, 0, n - 1);
    }
};