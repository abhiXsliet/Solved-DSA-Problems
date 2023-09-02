// https://leetcode.com/problems/extra-characters-in-a-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N*N) -> N-states * a loop for each state
    // SC = O(max(N, M)) vector space = N, set space = O(M)
    int solve_mem(string& s, int idx, unordered_set<string>& stt, vector<int>& dp) {
        int n = s.length();
        // base case
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        int minExtra   = n;
        string currStr = "";

        for (int i = idx; i < n; i++) {

            currStr.push_back(s[i]);
            
            int currExtra = (stt.find(currStr) == stt.end()) ? currStr.length() : 0;
            int remainingExtra = solve_mem(s, i+1, stt, dp);
            int total = currExtra + remainingExtra;

            minExtra = min(minExtra, total);
        }
        return dp[idx] = minExtra;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> stt;
        for (auto& word : dictionary) 
            stt.insert(word);

        int n = s.length();
        vector<int> dp(n+1, -1);
        return solve_mem(s, 0, stt, dp);
    }
};