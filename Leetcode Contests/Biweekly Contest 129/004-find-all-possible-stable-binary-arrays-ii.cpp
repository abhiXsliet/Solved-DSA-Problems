// https://leetcode.com/contest/biweekly-contest-129/problems/find-all-possible-stable-binary-arrays-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    int M = 1e9 + 7;
    
    int tab(int zeros, int ones, int limit) {
        vector<vector<vector<ll>>> dp(zeros + 1, vector<vector<ll>>(ones + 1, vector<ll>(3, 0)));

        // dp[i][j][k] : i no. of zeros, j no. of ones and
        // for k: we have 2-choices either 0 or 1
        // 0 means previously chosen 1 so currently choosing 0 and 1 means previously choosen 0 and currently choosing 1
        for (int i = 0; i <= min(zeros, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= min(ones, limit); j++) {
            dp[0][j][1] = 1;
        }

        for (int i = 1; i <= zeros; i++) {
            for (int j = 1; j <= ones; j++) {
                // ZEROS
                // dp[i][j][0]     -> i-zeros, j-1 and currently choosing 0 (previously it was 1)
                // dp[i - 1][j][0] -> i-1 no. of zeros, j-ones and currently choosing 0 (last no. is 0)
                // dp[i - 1][j][1] -> i-1 no. of zeros, j-ones and currently choosing 1 (last no. is 1)
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % M;    // total no. of zeros possibility with 0 or 1 comes at the last
                
                if (i > limit) { // we have taken extra zeros than limit so, remove all those extra zeros from total
                    dp[i][j][0] = (dp[i][j][0] - dp[i - (limit + 1)][j][1] + M) % M;
                }

                // ONES
                // dp[i][j][1]     -> i-zeros, j-ones and currently choosing 1 (previously it was 0)
                // dp[i][j - 1][0] -> i-zeros, j-1 no. of ones and currently choosing 0 (last no. is 0)
                // dp[i][j - 1][1] -> i-zeros, j-1 no. of ones and currently choosing 1 (last no. is 1)
                dp[i][j][1] = (dp[i][j - 1][1] + dp[i][j - 1][0]) % M;  // total no. of ones possibilites with 0 or 1 comes at the last
                
                if (j > limit) { // we have taken more ones than limit so, remove all those extra ones from total
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