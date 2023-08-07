// https://leetcode.com/problems/word-break/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2^N)
    // SC = O(N)
    bool solve(string s, unordered_set<string>& st, int index) {
        if(index == s.size()) return 1;

        for(int i = index; i < s.size(); i++) {
            if(st.count(s.substr(index, i+1-index)) && solve(s, st, i+1)) {
                return 1;
            }
        }
        return 0;
    }

    // TC = O(N^3)
    // SC = O(N)
    bool solveMem(string s, unordered_set<string>& st, int index, vector<int>& dp) {
        if(index == s.size()) return 1;

        if(dp[index] != -1) return dp[index];
        
        for(int i = index; i < s.size(); i++) {
            if(st.count(s.substr(index, i+1-index)) && solveMem(s, st, i+1, dp)) {
                return 1;
            }
        }
        return dp[index] = 0;
    }

    // TC = O(N^3)
    // SC = O(N)
    bool solveTab(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        // Analyze the base case
        dp[0] = 1;
                
        unordered_set<string> st;
        for(auto i : wordDict) st.insert(i);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && st.count(s.substr(j, i-j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i : wordDict) st.insert(i);
        // Recursive -> TLE
        // return solve(s, st, 0);
        

        // // Recursion + Memoization
        // vector<int> dp(s.size(), -1);
        // return solveMem(s, st, 0, dp);


        // Tabulation
        return solveTab(s, wordDict);
    }
};