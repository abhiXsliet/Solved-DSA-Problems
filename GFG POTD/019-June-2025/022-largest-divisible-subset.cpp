// http://geeksforgeeks.org/problems/largest-divisible-subset--170643/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void solve(int curr, int prev, vector<int> &arr, int n, vector<int> &subset, vector<int> &result) {
        if (curr >= n) {
            if (result.size() <= subset.size() && result < subset)
                result = subset;
            return;
        }
        
        if (prev == -1 || (arr[curr] % arr[prev] == 0)) {
            subset.push_back(arr[curr]);
            solve(curr + 1, curr, arr, n, subset, result);
            subset.pop_back();
        }
        solve(curr + 1, prev, arr, n, subset, result);
    }
    
    // TC : O(2^N * N)
    // SC : O(N)
    vector<int> approach_1(vector<int> &arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        vector<int> result;
        vector<int> subset;
        
        solve(0, -1, arr, n, subset, result);
        return result;
    }
    
    // TC : O(N * N)
    // SC : O(N)
    vector<int> approach_2(vector<int> &arr) {
        int n = arr.size();
        
        sort(rbegin(arr), rend(arr));
        
        vector<int> hash(n, -1);
        vector<int> dp(n, 1);
        
        int maxLen = 1, lastIdx = 0;
        
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (arr[j] % arr[i] == 0) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i]   = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }
            if (maxLen < dp[i]) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }
        
        vector<int> result;
        while (lastIdx != -1) {
            result.push_back(arr[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        return result;
    }
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // return approach_1(arr); // TLE 
        return approach_2(arr);
    }
};