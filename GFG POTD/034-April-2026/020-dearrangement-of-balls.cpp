// https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int pos, vector<bool> &used, int n) {
        if (pos == n) return 1;
        
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            if (used[i] || pos + 1 == i) continue;
            used[i] = true;
            ans += solve(pos + 1, used, n);
            used[i] = false;
        }
        return ans;
    }
    
    // TC : O(n!)
    // SC : O(n)
    int approach_1(int n) {
        vector<bool> used(n + 1, 0);
        return solve(0, used, n);
    }
    
    // TC : O(n)
    // SC : O(n)
    int approach_2(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i ++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
    
    // TC : O(n)
    // SC : O(1)
    int approach_3(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        long long a = 0, b = 1;
        for (int i = 3; i <= n; i ++) {
            long long c = (i - 1) * (b + a);
            a = b;
            b = c;
        }
        return b;
    }
  public:
    int derangeCount(int n) {
        // return approach_1(n);   // backtracking
        // return approach_2(n);
        return approach_3(n);
    }
};