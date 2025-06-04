// https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int mem(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        if (i >= s1.length() || j >= s2.length() || k >= s3.length())
            return 0;
            
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
            
        int take = 0;
        if (s1[i] == s2[j] && s2[j] == s3[k]) {
            take = 1 + mem(s1, s2, s3, i + 1, j + 1, k + 1, dp);
        }
        int notTake = max({mem(s1, s2, s3, i + 1, j, k, dp), mem(s1, s2, s3, i, j + 1, k, dp), mem(s1, s2, s3, i, j, k + 1, dp)});
        
        return dp[i][j][k] = max(take, notTake);
    }

    // TC : O(M * N * O)
    // SC : O(M * N * O)
    int approach_1(string &s1, string &s2, string &s3) {
        int m = s1.length(), n = s2.length(), o = s3.length();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(o + 1, -1)));
        return mem(s1, s2, s3, 0, 0, 0, dp);
    }

    // TC : O(M * N * O)
    // SC : O(M * N * O)
    int approach_2(string &s1, string &s2, string &s3) {
        int m = s1.length(), n = s2.length(), o = s3.length();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(o + 1, 0)));
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                for (int k = o - 1; k >= 0; k --) {
                    int take = 0;
                    if (s1[i] == s2[j] && s2[j] == s3[k]) {
                        take = 1 + dp[i + 1][j + 1][k + 1];
                    }
                    int notTake = max({dp[i + 1][j][k], dp[i][j + 1][k], dp[i][j][k + 1]});
                    dp[i][j][k] = max(take, notTake);
                }
            }
        }
        return dp[0][0][0];
    }
    
    // TC : O(M * N * O)
    // SC : O(N * O)
    int approach_3(string &s1, string &s2, string &s3) {
        int m = s1.length(), n = s2.length(), o = s3.length();
        vector<vector<int>> next(n + 1, vector<int>(o + 1, 0));
        vector<vector<int>> curr(n + 1, vector<int>(o + 1, 0));
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                for (int k = o - 1; k >= 0; k --) {
                    if (s1[i] == s2[j] && s2[j] == s3[k]) {
                        curr[j][k] = 1 + next[j + 1][k + 1];
                    } else {
                        curr[j][k] = max({
                            next[j][k], 
                            curr[j + 1][k], 
                            curr[j][k + 1]
                        });
                    }
                }
            }
            next = curr;
        }
        return next[0][0];
    }
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        // return approach_1(s1, s2, s3);
        // return approach_2(s1, s2, s3);
        return approach_3(s1, s2, s3);
    }
};