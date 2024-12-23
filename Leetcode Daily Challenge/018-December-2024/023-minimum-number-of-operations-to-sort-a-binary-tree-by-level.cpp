// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/



#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:    
    // TC : O(N*log(N) + N + N)
    // SC : O(N)
    int getMinSwapsAtEachLevel(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> sortedArr;   // can be done use map : store the orginal indices of ele and sort the given array
        for (int i = 0; i < n; i ++) {
            sortedArr.push_back({arr[i], i});
        }
        
        sort(begin(sortedArr), end(sortedArr)); // now make this sorted vector unsorted to count the swaps required for sorting 

        int cntSwaps = 0;
        for (int i = 0; i < n; i ++) {
            int ele = sortedArr[i].first;
            int idx = sortedArr[i].second;
            if (i != idx) {
                swap(sortedArr[i], sortedArr[idx]);
                cntSwaps ++;
                i --;
            }
        }
        return cntSwaps;
    }

    // TC : O(L * Nlog(N))
    // SC : O(L * N)
    int approach_1(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cntSwaps = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> storeLevelNodes;
            while (n --) {
                TreeNode* it = q.front();
                q.pop();
                storeLevelNodes.push_back(it -> val);
                if (it -> left) q.push(it -> left);
                if (it ->right) q.push(it ->right);
            }
            cntSwaps += getMinSwapsAtEachLevel(storeLevelNodes);
        }
        return cntSwaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        return approach_1(root);    // BFS approach
    }
};