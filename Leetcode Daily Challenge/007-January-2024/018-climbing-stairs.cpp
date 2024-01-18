// https://leetcode.com/problems/climbing-stairs/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    int dp[46];
    // TC : O(2^N)
    // SC : O(N) -> Recursive Depth
    int solve_rec(int n) {
        if (n  < 0) return 0;
        if (n == 0) return 1;

        int way_1 =  solve_rec(n-1);
        int way_2 =  solve_rec(n-2);

        return way_1 + way_2;
    }

    // TC : O(N)
    // SC : O(N) -> dp array
    int solve_mem(int n) {
        if (n  < 0) return 0;
        if (n == 0) return 1;

        if (dp[n] != -1) return dp[n];

        int way_1 =  solve_mem(n-1);
        int way_2 =  solve_mem(n-2);

        return dp[n] = (way_1 + way_2);
    }

    // TC : O(N)
    // SC : O(N) -> dp array
    int solve_tab(int n) {
        vector<int> dp(n+1, 0);

        dp[0] = 1;

        if (n > 0) 
            dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            int way_1 = dp[i - 1];
            int way_2 = dp[i - 2];

            dp[i] = (way_1 + way_2);
        }
        return dp[n];
    }

    // TC : O(N)
    // SC : O(1)
    int solve_so(int n) {
        int prev = 1;

        int curr = 0;
        if (n > 0) 
            curr = 1;

        for (int i = 2; i <= n; i++) {
            int way_1 = curr;
            int way_2 = prev;

            prev = curr;
            curr = (way_1 + way_2);
        }
        return curr;
    }
public:
    int climbStairs(int n) {
        // return solve_rec(n);

        // memset(dp, -1, sizeof(dp));
        // return solve_mem(n); 

        // return solve_tab(n); 

        return solve_so(n); 
    }
};