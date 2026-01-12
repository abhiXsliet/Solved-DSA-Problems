// https://leetcode.com/problems/pyramid-transition-matrix/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> dp;

    // L^(n−1) × L^(n−2) × ... × L^1
    // O( L^( n(n−1)/2 ) )
    // TC : O(L^n) where L = length of vector<char> in mpp & n = no. of pairs made by bottom string
    // SC : O(n)
    bool solve(string bottom, string above, int idx, unordered_map<string, vector<char>> &mpp) {
        if (bottom.length() == 1) 
            return true;
        
        string key = bottom + "_" + above + "_" + to_string(idx);
        if (dp.count(key)) return dp[key];

        if (idx == bottom.length() - 1) 
            return dp[key] = solve(above, "", 0, mpp);

        string pair = bottom.substr(idx, 2);
        if (!mpp.count(pair)) 
            return dp[key] = false;

        for (char &ch : mpp[pair]) {
            above.push_back(ch);
            if (solve(bottom, above, idx + 1, mpp)) 
                return dp[key] = true;
            above.pop_back();
        }
        return dp[key] = false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mpp;
        for (string &str : allowed) {
            mpp[str.substr(0, 2)].push_back(str[2]);
        }

        string above = "";
        return solve(bottom, above, 0, mpp);
    }
};