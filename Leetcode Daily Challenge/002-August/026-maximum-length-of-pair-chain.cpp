// https://leetcode.com/problems/maximum-length-of-pair-chain/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool isCmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    // TC = O(N*log(N)) where N = pairs.size();
    // SC = O(1)
    int solve_greedy(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), isCmp);

        int n = pairs.size();
        int cnt = 1;
        int lastPairEnd = pairs[0][1];

        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > lastPairEnd) {
                cnt++;
                lastPairEnd = pairs[i][1];
            }
        }

        return cnt;
    }

    // TC = O(N * log(N)) + O(N*N) 
    // SC = O(N*N)
    int solve_mem(vector<vector<int>>& pairs, vector<vector<int>>& dp, int curr, int prev) {
        sort(pairs.begin(), pairs.end());
        
        // base case
        if (curr == pairs.size()) return 0;

        if (dp[curr][prev+1] != -1) return dp[curr][prev+1];
        
        int incl = 0;
        if (prev == -1 || pairs[curr][0] > pairs[prev][1])
            incl = 1 + solve_mem(pairs, dp, curr+1, curr);

        int excl = 0 + solve_mem(pairs, dp, curr+1, prev);

        return dp[curr][prev+1] = max(incl, excl);
    }

    // TC = O(N*log(N)) + O(N*N)
    // SC = O(N*N)
    int solve_tab(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n - 1; curr >= 0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                
                int incl = 0;
                if (prev == -1 || pairs[curr][0] > pairs[prev][1])
                    incl = 1 + dp[curr+1][curr+1];

                int excl = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(incl, excl);

            }
        }
        return dp[0][0];
    }

    // TC = O(N*log(N)) + O(N*N)
    // SC = O(N)
    int solve_so(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> curr_row(n+1, 0);
        vector<int> next_row(n+1, 0);
        
        for(int curr = n - 1; curr >= 0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                
                int incl = 0;
                if (prev == -1 || pairs[curr][0] > pairs[prev][1])
                    incl = 1 + next_row[curr+1];

                int excl = 0 + next_row[prev+1];

                curr_row[prev+1] = max(incl, excl);

            }
            next_row = curr_row;
        }
        return next_row[0];
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // return solve_greedy(pairs);


        // // Recursion + Memoization  
        // int n = pairs.size();  // n = 1000 (given)    
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve_mem(pairs, dp, 0, -1);


        // // Tabulation
        // return solve_tab(pairs);


        // Space - Optimization
        return solve_so(pairs);
    }
};