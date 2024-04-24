// https://leetcode.com/problems/n-th-tribonacci-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int mem(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        if (dp[n] != -1) return dp[n];

        return dp[n] = mem(n - 1, dp) + mem(n - 2, dp) + mem(n - 3, dp);
    }
    
    // TC : O(N)
    // SC : O(N)
    int tab(int n) {
        if (n <= 1) return n;

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }

    // TC : O(N)
    // SC : O(1)
    int so(int n) {
        if (n <= 1) return n;

        int a = 0;
        int b = 1;
        int c = 1;

        for (int i = 3; i <= n; i++) {
            int curr = a + b + c;
            a = b;
            b = c;
            c = curr;
        }
        return c;
    }
public:
    int tribonacci(int n) {
        // vector<int> dp(n+1, -1);
        // return mem(n, dp);

        // return tab(n);

        return so(n);
    }
};