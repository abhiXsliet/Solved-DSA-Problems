// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void makeGraph(unordered_map<int, vector<int>>& adj, int parent, TreeNode* curr) {
        if (curr == NULL) {
            return;
        }

        if (parent != -1) {
            adj[curr -> val].push_back(parent);
        }

        if (curr -> left) {
            adj[curr -> val].push_back(curr -> left -> val);
        }

        if (curr -> right) {
            adj[curr -> val].push_back(curr -> right -> val);
        }

        makeGraph(adj, curr -> val, curr -> left);
        makeGraph(adj, curr -> val, curr -> right);
    }

    // GRAPH TRAVERSAL : Two Times
    // T.C : O(n) - visiting all nodes
    // S.C : O(n) - storing all nodes in graph
    int solve_approach_1(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);

        // Apply BFS From Start
        queue<int> que;
        unordered_set<int> vis;
        
        que.push(start);
        vis.insert(start);
        int minutes = 0;

        while (!que.empty()) {
            // current level size
            int n = que.size();
            while (n--) {
                int curr = que.front();
                que.pop();

                for (auto& neigh : adj[curr]) {
                    
                    if (vis.find(neigh) == vis.end()) {
                        que.push(neigh);
                        vis.insert(neigh);
                    }
                }
            }
            minutes ++;
        }

        return minutes-1;
    }

    // ONE PASS SOLUTION
    // TC : O(N)
    // SC : O(N)
    int solve_approach_2(TreeNode* root, int start, int& result) {
        if (root == NULL) {
            return 0;
        }

        int LH = solve_approach_2(root -> left , start, result);
        int RH = solve_approach_2(root -> right, start, result);

        if(root->val == start) {
            result = max(LH, RH);
            return -1;
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }
        // flow not reach here
        return 0;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        // return solve_approach_1(root, start);

        int result = INT_MIN;
        solve_approach_2(root, start, result);
        return result;
    }
};