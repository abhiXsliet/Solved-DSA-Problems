// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/



#include <bits/stdc++.h>
using namespace std;

// ----------------------------------- Approach - 1 (Brute) ----------------------------------------------------
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// TC : O(N^2)
// SC : O(N)
class FindElements {
public:
    TreeNode* node;
    FindElements(TreeNode* root) {
        node = root;
    }
    
    bool find(int target) {
        if (!node) return false;
        return solve(node, 0, target);
    }

    bool solve(TreeNode* node, int value, int target) {
        if (!node) 
            return false;
        if (value == target) 
            return true;

        node -> val = value;
        return solve(node ->  left, 2 * value + 1, target) |
               solve(node -> right, 2 * value + 2, target);
    }
};

// -------------------------------------- Approach - 2 (Optimal: Using set + DFS) ----------------------------------------------
// TC : O(N)
// SC : O(N)
class FindElements {
public:
    unordered_set<int> st;
    void solve(TreeNode* node, int value) {
        if (!node) return;

        node -> val = value;
        st.insert(value);

        solve(node ->  left, 2 * value + 1);
        solve(node -> right, 2 * value + 2);
    }

    FindElements(TreeNode* root) {
        st.clear();
        solve(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

// -------------------------------------- Approach - 3 (Optimal: Using set + BFS) ----------------------------------------------
// TC : O(N)
// SC : O(N)
class FindElements {
public:
    unordered_set<int> st;
    void BFS(TreeNode* root, int value) {
        queue<TreeNode*> q;
        root -> val = value;
        q.push(root);
        while (!q.empty()) {
            TreeNode* fNode = q.front();
            q.pop();
            
            st.insert(fNode -> val);

            if (fNode ->  left) {
                fNode ->  left -> val = (2 * fNode -> val + 1);
                q.push(fNode ->  left);
            }
            if (fNode -> right) {
                fNode -> right -> val = (2 * fNode -> val + 2);
                q.push(fNode -> right);
            }
        }
    }

    FindElements(TreeNode* root) {
        st.clear();
        BFS(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
Your FindElements object will be instantiated and called as such:
FindElements* obj = new FindElements(root);
bool param_1 = obj->find(target);
 */