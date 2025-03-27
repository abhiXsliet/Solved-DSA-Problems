// https://leetcode.com/problems/sum-of-k-subarrays-with-length-at-least-m/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int NEG_INF = -1000000000;
    int n, m;
    vector<int> nums;
    int t[2001][2001][3];

    int solve(vector<int> &pSum, int k, int i, bool canContinue) {
        if (i == n) return k == 0 ? 0 : NEG_INF;

        if (t[k][i][canContinue] != -1)
            return t[k][i][canContinue];

        int sum = NEG_INF;
        if (canContinue) {
            sum = max(sum, nums[i] + solve(pSum, k, i + 1, 1));
            sum = max(sum, solve(pSum, k, i, 0));

        } else {
            if (k == 0) return 0;
            sum = max(sum, solve(pSum, k, i + 1, 0));
            
            if (i + m - 1 < n) {
                int currSum = (pSum[i + m - 1] - (i >= 1 ? pSum[i - 1] : 0));
                int take =  currSum + solve(pSum, k - 1, i + m, 1);
                sum = max(sum, take);
            }
        }
        return t[k][i][canContinue] = sum;
    }

    int top_down(vector<int> &pSum, int k) {
        memset(t, -1, sizeof(t));
        return solve(pSum, k, 0, 0);
    }
public:
    // TC : O(N * N)
    // SC : O(N * N)
    int maxSum(vector<int>& nums, int k, int m) {
        n = nums.size();
        this -> m = m;
        this -> nums = nums;

        vector<int> prefSum(n, nums[0]);
        for (int i = 1; i < n; i ++) {
            prefSum[i] = (prefSum[i - 1] + nums[i]);
        }

        return top_down(prefSum, k);
    }
};