// https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPowerOf5(int num) {
        if (num <= 0) return 0;
        
        double x = log(num) / log(5);
        return fabs(x- round(x)) < 1e-9;
    }
    
    bool isValidCut(string &s, int start, int end) {
        if (s[start] == '0') return 0;
        
        int decimal = 0;
        for (int i = start; i <= end; i ++) {
            decimal = (decimal * 2 + (s[i] - '0'));
        }
        return isPowerOf5(decimal);
    }
    
    int solve(string &s, int i, vector<int> &dp) {
        if (i >= s.length()) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        int minCuts = INT_MAX;
        for (int j = i; j < s.length(); j ++) {
            if (isValidCut(s, i, j)) {
                int cuts = solve(s, j + 1, dp);
                if (cuts != -1) 
                    minCuts = min(minCuts, 1 + cuts);
            }
        }
        return dp[i] = (minCuts == INT_MAX) ? -1 : minCuts;
    }
    
    // TC : O(N^2)
    // SC : O(N)
    int approach_1(string &s) {
        vector<int> dp(s.length() + 1, -1);
        return solve(s, 0, dp);
    }

    // TC : O(N^2)
    // SC : O(N)
    int approach_2(string &s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = dp[n - 1] = 0;
        for (int i = n - 1; i >= 0; i --) {
            int minCuts = INT_MAX;
            for (int j = i; j < n; j ++) {
                if (isValidCut(s, i, j)) {
                    int cuts = dp[j + 1];
                    if (cuts != -1) 
                        minCuts = min(minCuts, 1 + cuts);
                }
            }
            dp[i] = (minCuts == INT_MAX) ? -1 : minCuts;
        }
        return dp[0];
    }
  public:
    int cuts(string s) {
        // return approach_1(s);    // memoization
        return approach_2(s);    // tabulation
    }
};