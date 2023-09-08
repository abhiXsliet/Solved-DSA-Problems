// https://leetcode.com/problems/combination-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
// TC = O(2^target * k)
// Where: target is the input target value.
// 'k' is the time complexity for the final operation when the base case is reached (e.g., pushing the store array into the ans array).

// SC = O( k * x ) where x is the total no. of combinations
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, 
                int idx, vector<int>& store) {
        
        // base case
        if (idx == candidates.size()) {
            if (target == 0) {
                ans.push_back(store);
            }
            return ;
        }
        // pick up the element
        if (candidates[idx] <= target) {
            store.push_back(candidates[idx]);
            solve(candidates, target - candidates[idx], ans, idx, store);
            store.pop_back();
        }
        // not pick up the element
        solve(candidates, target, ans, idx+1, store);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> store;
        solve(candidates, target, ans, 0, store);
        return ans;
    }
};