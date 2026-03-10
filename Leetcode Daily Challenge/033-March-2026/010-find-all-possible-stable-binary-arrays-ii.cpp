// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int M = 1e9 + 7;
    
    int tab(int zeros, int ones, int limit) {
        vector<vector<vector<ll>>> dp(zeros + 1, vector<vector<ll>>(ones + 1, vector<ll>(3, 0)));

        // dp[i][j][k] : i no. of zeros, j no. of ones and k = start with 0 or 1 (prev it was 0 or 1)
        for (int i = 0; i <= min(zeros, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= min(ones, limit); j++) {
            dp[0][j][1] = 1;
        }

        for (int i = 1; i <= zeros; i++) {
            for (int j = 1; j <= ones; j++) {
                // ZEROs
                // [i-1] zeros with 0 at the last and [i-1] zeross with 1 at the last
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % M;    
                
                if (i > limit) { // we have taken extra zeross than limit so, remove all those cases from total
                    dp[i][j][0] = (dp[i][j][0] - dp[i - (limit + 1)][j][1] + M) % M;
                }

                // ONES
                dp[i][j][1] = (dp[i][j - 1][1] + dp[i][j - 1][0]) % M;
                
                if (j > limit) {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - (limit + 1)][0] + M) % M;
                }
            }
        }

        return (dp[zeros][ones][0] + dp[zeros][ones][1]) % M;
    }
public:
    int numberOfStableArrays(int zeros, int ones, int limit) {
        return tab(zeros, ones, limit);
    }
};