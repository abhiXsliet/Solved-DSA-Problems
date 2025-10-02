// https://www.geeksforgeeks.org/problems/combination-sum-iii--111703/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void solve(int n, int k, int sum, int start, vector<int> &temp, vector<vector<int>> &result) {
        if (k == 0 || sum >= n) {
            if (k == 0 && sum == n) result.push_back(temp);
            return;
        }
        
        for (int val = start; val <= 9; val ++) {
            temp.push_back(val);
            solve(n, k - 1, sum + val, val + 1, temp, result);
            temp.pop_back();
        }
    }
  public:
    // TC : O(K * 2^9)
    // SC : O(K)
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(n, k, 0, 1, temp, result);
        return result;
    }
};