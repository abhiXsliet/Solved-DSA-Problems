// https://leetcode.com/problems/combination-sum-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2^n * klog(n)) where k times log(n) time is req. for insertion in set
    // SC = O(k * x) where k is the set size and x is the total no. of combinations
    void solve_brute(vector<int>& arr, int tar, set<vector<int>>& ans, 
                vector<int>& store, int idx) {
        
        // base case
        if (idx == arr.size()) {
            if (tar == 0) {
                ans.insert(store);
            }
            return;
        }

        // pick up the element
        if (arr[idx] <= tar) {
            store.push_back(arr[idx]);
            solve_brute(arr, tar - arr[idx], ans, store, idx+1);
            store.pop_back();
        }
        while (idx < arr.size()-1 && arr[idx] == arr[idx+1]) {
            idx++;
        }

        // not pick up the element
        solve_brute(arr, tar, ans, store, idx+1);
    }

    vector<vector<int>> bruteSolve(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> store;
        sort(begin(candidates), end(candidates));
        solve_brute(candidates, target, ans, store, 0);

        //convert ans set into 2D vector
        vector<vector<int>> res;
        for (auto& i : ans) {
            res.push_back(i);
        }

        return res;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return bruteSolve(candidates, target);
    }
};