// https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution{
private:
    
    pair<string, int> solve_mem(vector<int>& p, int i, int j, vector<vector<pair<string, int>>>& dp) {
        if (i == j) {
            string s = "";
            s += 'A' + i - 1;
            return {s, 0};
        }
        
        if (dp[i][j].second != -1) return dp[i][j];
        
        string str = "";
        int mini = 1e9;
        
        for (int k = i; k < j; k++) {
            auto pair_1 = solve_mem(p, i, k, dp);
            auto pair_2 = solve_mem(p, k+1, j, dp);
            
            int x = pair_1.second + pair_2.second + p[i - 1] * p[k] * p[j];
            
            string new_s = "";
            new_s = "(" + pair_1.first + pair_2.first + ")";
            
            if (mini > x) {
                mini = x;
                str  = new_s;
            }
        }
        return dp[i][j] = {str, mini};
    }
public:
    string matrixChainOrder(vector<int> &p){
        int n = p.size();
        vector<vector<pair<string, int>>> dp(n, vector<pair<string, int>>(n, {"", -1}));
        auto pair = solve_mem(p, 1, n - 1, dp);
        return pair.first;
    }
};