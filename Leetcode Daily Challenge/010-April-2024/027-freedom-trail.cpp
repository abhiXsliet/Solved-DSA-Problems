// https://leetcode.com/problems/freedom-trail/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countSteps(int ringIdx, int i, int n) {
        int dist           = abs(ringIdx - i);
        int wrapAroundDist = n - dist;
        return min(dist, wrapAroundDist);
    }

    // TC (Recursive) : O(N ^ M)
    // SC (Recursive) : O(N) -> Depth of Recursion

    // TC : O(N * M) Where N = length of string ring
    // SC : O(N * M) Where M = length of string key
    int mem(int ringIdx, int keyIdx, string& ring, string& key, vector<vector<int>>& dp) {
        if (keyIdx == key.length()) return 0;

        if (dp[ringIdx][keyIdx] != -1) return dp[ringIdx][keyIdx];

        int ans = INT_MAX;
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIdx]) {
                int totalSteps = countSteps(ringIdx, i, ring.length()) + 1 + 
                                 mem(i, keyIdx + 1, ring, key, dp);
                
                ans = min(ans, totalSteps);
            }
        }

        return dp[ringIdx][keyIdx] = ans;
    }

    // TC : O(N * M * M)
    // SC : O(N * M)
    int tab(string& ring, string& key) {
        int m = ring.length(), n = key.length();

        vector<vector<int>> dp(m, vector<int>(n + 1, INT_MAX));

        for (int ringIdx = 0; ringIdx < m; ringIdx ++) {
            dp[ringIdx][n] = 0;
        }

        for (int keyIdx = n - 1; keyIdx >= 0; keyIdx --) {
            for (int ringIdx = 0; ringIdx < m; ringIdx ++) {

                int ans = INT_MAX;
                for (int i = 0; i < m; i++) {
                    if (ring[i] == key[keyIdx]) {
                        int totalSteps = countSteps(ringIdx, i, ring.length()) + 1 + dp[i][keyIdx + 1];
                        
                        ans = min(ans, totalSteps);
                    }
                }

                dp[ringIdx][keyIdx] = ans;
            }
        }

        return dp[0][0];
    }
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.length(), n = key.length();
        
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return mem(0, 0, ring, key, dp);

        return tab(ring, key);
    }
};