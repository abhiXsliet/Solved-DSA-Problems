// https://leetcode.com/problems/n-ary-tree-postorder-traversal/




#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    // TC : O(N) -> visiting every node twice only
    // SC : O(H) -> Recursive Stack Space
    void solve(Node* root, vector<int>& res) {
        if (!root) return;

        vector<Node*> childrens = root -> children;
        
        for (int i = 0; i < childrens.size(); i ++) {
            solve(childrens[i], res);
            res.push_back(childrens[i] -> val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        solve(root, result);
        if (root != NULL) 
            result.push_back(root -> val);
        return result;
    }
};