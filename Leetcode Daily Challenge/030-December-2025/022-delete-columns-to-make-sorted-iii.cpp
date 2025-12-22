// https://leetcode.com/problems/delete-columns-to-make-sorted-iii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int lis = 0;

        vector<int> dp(m, 1);

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < i; j ++) {

                bool isValid = true;

                for (int k = 0; k < n; k ++) {
                    // valid : strs[k][j] <= strs[k][i]
                    if (strs[k][j] > strs[k][i]) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            lis = max(lis, dp[i]);
        }

        return m - lis;
    }
};