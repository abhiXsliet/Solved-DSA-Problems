// https://leetcode.com/problems/maximum-number-of-points-with-cost/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(M*N*N)
    // SC : O(M*N)
    ll brute(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<ll>> dp(m, vector<ll>(n, 0LL));

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                dp[i][j] = points[i][j];
            }
        }

        for (int i = 1; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                ll score = dp[i][j];

                for (int k = 0; k < n; k ++) {
                    ll val = dp[i][j];
                    val   += dp[i - 1][k];
                    val   -= abs(k - j);
                    score  = max(score, val);
                }

                dp[i][j] = score;
            }
        }

        ll ans = 0;
        for (int j = 0; j < n; j ++) {
            ans = max(ans, dp[m - 1][j]);
        }
        return ans;
    }

    // TC : O(M*N*N)
    // SC : O(N)
    ll better(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        vector<ll> prev(n);
        for (int j = 0; j < n; j ++) {
            prev[j] = points[0][j];
        }

        for (int i = 1; i < m; i ++) {

            vector<ll> curr(n);
            
            for (int j = 0; j < n; j ++) {
                
                curr[j]  = points[i][j];
                ll score = curr[j];

                for (int k = 0; k < n; k ++) {
                    ll val = curr[j];
                    val   += prev[k];
                    val   -= abs(k - j);
                    score  = max(score, val);
                }
                curr[j] = score;
            }
            prev = curr;
        }

        ll ans = 0;
        for (int j = 0; j < n; j ++) {
            ans = max(ans, prev[j]);
        }
        return ans;
    }
    
    // TC : O(M * N)
    // SC : O(N)
    ll optimal(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<ll> prev(n);
        for (int j = 0; j < n; j ++) {
            prev[j] = points[0][j];
        }

        for (int i = 1; i < m; i ++) {
            
            vector<ll> prefix(n);
            prefix[0] = prev[0];
            for (int j = 1; j < n; j ++) {
                prefix[j] = max(prev[j], prefix[j - 1] - 1);
            }

            vector<ll> suffix(n);
            suffix[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0; j --) {
                suffix[j] = max(prev[j], suffix[j + 1] - 1);    // -1 is for col. difference
            }

            vector<ll> curr(n);
            for (int j = 0; j < n; j ++) {
                curr[j] = max(prefix[j], suffix[j]) + points[i][j];
            }
            prev = curr;
        }

        return *max_element(begin(prev), end(prev));
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        // return brute(points);

        // return better(points);      // Space Optimize

        return optimal(points);     // Time Optimize
    }
};