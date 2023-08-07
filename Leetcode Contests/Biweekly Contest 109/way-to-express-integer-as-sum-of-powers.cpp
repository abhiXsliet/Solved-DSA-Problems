// https://leetcode.com/contest/biweekly-contest-109/problems/ways-to-express-an-integer-as-sum-of-powers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
    
    // TC = O(2^N)
    // SC = O(N) -> Recursion depth on call stack
    int solveRec(int num, int n, int& x) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        int power = pow(num, x);
        if(n < power) return 0;
        
        int include = solveRec(num + 1, n - power, x) % mod;
        int exclude = solveRec(num + 1, n, x) % mod;
        
        return (include + exclude) % mod;
    }
    
    // TC = O(N^2)
    // SC = O(N^2) + O(N) for recursive call stack
    int solveMem(int num, int n, int& x, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        int power = pow(num, x);
        if(n < power) return 0;
        
        if(dp[num][n] != -1) return dp[num][n];
        
        int include = solveMem(num + 1, n - power, x, dp) % mod;
        int exclude = solveMem(num + 1, n, x, dp) % mod;
        
        return dp[num][n] = (include + exclude) % mod;
    }
public:
    int numberOfWays(int n, int x) {
        // Recursive -> TLE
        // return solveRec(1, n, x);

        
        // Recursion + Memoization
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solveMem(1, n, x, dp);
    }
};