// https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> sum(n, vector<int>(n, 0));

        // Precompute freq sum for all ranges
        for(int i = 0; i < n; i++){
            sum[i][i] = freq[i];
            for(int j = i+1; j < n; j++){
                sum[i][j] = sum[i][j-1] + freq[j];
            }
        }

        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(i == j){
                    dp[i][j] = freq[i];
                    continue;
                }
                dp[i][j] = INT_MAX;

                for(int k = i; k <= j; k++){
                    int left = (k > i) ? dp[i][k-1] : 0;
                    int right = (k < j) ? dp[k+1][j] : 0;
                    dp[i][j] = min(dp[i][j], left + right + sum[i][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};