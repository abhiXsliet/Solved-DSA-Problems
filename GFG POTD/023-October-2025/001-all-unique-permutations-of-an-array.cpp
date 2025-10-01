// https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void solve(vector<int> &arr, int idx, set<vector<int>> &st) {
        if (idx == arr.size()) {
            st.insert(arr);
            return;
        }
        
        for (int i = idx; i < arr.size(); i ++) {
            swap(arr[i], arr[idx]);
            solve(arr, idx + 1, st);
            swap(arr[i], arr[idx]);
        }
    }
    
    void optimized(vector<int> &arr, int idx, vector<vector<int>> &result) {
        if (idx == arr.size()) {
            result.push_back(arr);
            return;
        }
        
        unordered_set<int> used;
        for (int i = idx; i < arr.size(); i ++) {
            if (used.count(arr[i])) continue;
            used.insert(arr[i]);
            
            swap(arr[i], arr[idx]);
            optimized(arr, idx + 1, result);
            swap(arr[i], arr[idx]);
        }
    }
    
    // TC : O(N * N!)
    // SC : O(N * N!) at worst every permutation could be unique
    vector<vector<int>> approach_1(vector<int> &arr) {
        set<vector<int>> st;
        solve(arr, 0, st);
        vector<vector<int>> result;
        for (auto &it : st) {
            result.push_back(it);
        }
        return result;
    }
    
    // TC : O(N * N!)
    // SC : O(N)
    vector<vector<int>> approach_2(vector<int> &arr) {
        vector<vector<int>> result;
        optimized(arr, 0, result);
        sort(begin(result), end(result));
        return result;
    }
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // return approach_1(arr);
        return approach_2(arr);
    }
};