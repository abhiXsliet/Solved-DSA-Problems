// https://leetcode.com/problems/partition-array-for-maximum-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int t[501];
    // TC (Without Memoization) : O(k^n) for every idx there are k-possiblity
    // TC (With    Memoization) : O(n*k)
    // SC                       : O(501) ~= O(1)
    int solve_mem(vector<int>& arr, int k, int idx) {
        if (idx >= n) return 0;

        if (t[idx] != -1) return t[idx];

        int result  = 0;
        int currMax = -1;

        for (int i = idx; i < n && i - idx + 1 <= k; i++) {

            currMax = max(currMax, arr[i]);

            // current subarray = arr[idx to i]
            result = max(result, currMax*(i-idx+1) + solve_mem(arr, k, i+1));
        }

        return t[idx] = result;
    }

    // TC : O(n * k) Where n = arr.size();
    // SC : O(n)
    int solve_tab_1(vector<int>& arr, int k) {
        vector<int> dp(n+1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            int result  = 0;
            int currMax = -1;

            for (int i = idx; i < n && i - idx + 1 <= k; i++) {

                currMax = max(currMax, arr[i]);

                // current subarray = arr[idx to i]
                result = max(result, currMax*(i-idx+1) + dp[i + 1]);
            }

            dp[idx] = result;
        }

        return dp[0];
    }

    // TC : O(n * k) Where n = arr.size();
    // SC : O(n)
    int solve_tab_2(vector<int>& arr, int k) {
        //dp[i] = Maximum sum for the partition arr of size i
        vector<int> dp(n+1, 0);

        for (int idx = 1; idx <= n; idx ++) {
            
            int currMax = -1;
             
            for (int j = 1; j <= k && idx - j >= 0; j++) {

                currMax = max(currMax, arr[idx - j]);

                dp[idx]  = max(dp[idx], currMax*j + dp[idx - j]);
                
            }
        }

        return dp[n];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();

        // memset(t, -1, sizeof(t));
        // return solve_mem(arr, k, 0);

        // return solve_tab_1(arr, k);

        return solve_tab_2(arr, k);
    }
};