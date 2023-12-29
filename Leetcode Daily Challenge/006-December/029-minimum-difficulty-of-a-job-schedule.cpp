// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[11][301];
    // TC : O(d * n * n)
    // SC : O(d * n)
    int solve_mem(vector<int>& jobDifficulty, int d, int idx, int n) {
        if (d == 1) 
            return *max_element(begin(jobDifficulty)+idx, end(jobDifficulty));

        if (t[d][idx] != -1) 
            return t[d][idx];

        int result  = INT_MAX;
        int maxDiff = INT_MIN;

        for (int i = idx; i <= n-d; i++) {
            maxDiff = max(maxDiff, jobDifficulty[i]);

            result  = min(result, maxDiff + solve_mem(jobDifficulty, d - 1, i + 1, n)); 
        }

        return t[d][idx] = result;
    }

    // TC : O(d * n * n)
    // SC : O(d * n)
    int solve_tab(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        // dp[i][j] -> In 'i' days, min difficulty of doing job from j to n - 1 indexes
        vector<vector<int>> dp(d+1, vector<int>(n+1, 0));

        // if day = 1, do all the job on the 1st day itself
        for (int i = 0; i < n; i++) {
            dp[1][i] = *max_element(begin(jobDifficulty)+i, end(jobDifficulty));
        }

        // from day = 2 --------->
        for (int day = 2; day <= d; day++) {
            for (int i = n-day; i >= 0; i--) {  // indices 

                int result  = INT_MAX;
                int maxDiff = INT_MIN;

                for (int j = i; j <= n - day; j++) {
                    maxDiff = max(maxDiff, jobDifficulty[j]);

                    result = min(result, maxDiff + dp[day - 1][j + 1]);
                }

                dp[day][i] = result;
            }
        }

        return dp[d][0];
    }

    // TC : O(d * n * n)
    // SC : O(n)
    int solve_so(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        vector<int> curr(n+1, 0);
        vector<int> prev(n+1, 0);

        // if day = 1, do all the job on the 1st day itself
        for (int i = 0; i < n; i++) {
            curr[i] = *max_element(begin(jobDifficulty)+i, end(jobDifficulty));
        }

        // from day = 2 --------->
        for (int day = 2; day <= d; day++) {
            prev = curr;
            fill(curr.begin(), curr.end(), INT_MAX);
            for (int i = n-day; i >= 0; i--) {  // indices 

                int result  = INT_MAX;
                int maxDiff = INT_MIN;

                for (int j = i; j <= n - day; j++) {
                    maxDiff = max(maxDiff, jobDifficulty[j]);

                    result = min(result, maxDiff + prev[j + 1]);
                }

                curr[i] = result;
            }
        }

        return curr[0];
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) 
            return -1;

        // memset(t, -1, sizeof(t));
        // return solve_mem(jobDifficulty, d, 0, n);

        // return solve_tab(jobDifficulty, d);

        return solve_so(jobDifficulty, d);
    }
};