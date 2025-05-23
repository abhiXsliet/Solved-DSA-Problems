// https://www.geeksforgeeks.org/problems/dice-throw5349/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int dp[51][50 * 50];
    
    int mem(int m, int n, int x) {
        if (n == 0) {
            return x == 0; 
        }
        
        if (dp[n][x] != -1)
            return dp[n][x];
        
        int ans = 0;
        for (int i = 1; i <= m; i ++) {
            ans += mem(m, n - 1, x - i);
        }
        return dp[n][x] = ans;
    }
    
    // TC : O(M * N * X)
    // SC : O(N * X)
    int approach_1(int m, int n, int x) {
        memset(dp, -1, sizeof(dp));
        return mem(m, n, x);
    }
    
    // TC : O(M * N * X)
    // SC : O(N * X)
    int approach_2(int m, int n, int x) {
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i ++) {
            for (int s = 1; s <= x; s ++) {
                for (int face = 1; face <= m; face ++) {
                    if (s - face >= 0) {
                        dp[i][s] += dp[i - 1][s - face];
                    }
                }
            }
        }
        
        return dp[n][x];
    }
  public:
    int noOfWays(int m, int n, int x) {
        // return approach_1(m, n, x);
        return approach_2(m, n, x);
    }
};