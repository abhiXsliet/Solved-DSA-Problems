// https://leetcode.com/problems/combination-sum-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2^n * klog(n)) where k times log(n) time is req. for insertion in set
    // SC = O(k * x) where k is the set size and x is the total no. of combinations
    void solve_brute(vector<int>& arr, int tar, set<vector<int>>& ans, 
                vector<int>& store, int idx) {
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

    vector<vector<int>> way_1(vector<int>& candidates, int target) {
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

    // TC : O(2^N)
    // SC : O(N)
    void solve(vector<int>& arr, int tar, vector<vector<int>>& res, vector<int>& store, int idx) {
        if (tar  < 0) return;
        if (tar == 0) {
            res.push_back(store);
            return;
        }

        for (int i = idx; i < arr.size(); i ++) {
            if (i > idx && arr[i] == arr[i - 1]) // skip duplicate
                continue;
            store.push_back(arr[i]);
            solve(arr, tar - arr[i], res, store, i + 1);
            store.pop_back();
        }
    }

    vector<vector<int>> way_2(vector<int>& candidates, int target) {
        vector<int> store;
        vector<vector<int>> res;
        sort(begin(candidates), end(candidates));
        solve(candidates, target, res, store, 0);
        return res;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // return way_1(candidates, target);

        return way_2(candidates, target);
    }
};