// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[20001][4];
    int Helper (vector<int>& subarraySum, int k, int i, int cnt) {
        if (cnt == 0) return 0;
        if (i >= subarraySum.size()) return INT_MIN;

        if (t[i][cnt] != -1) return t[i][cnt];

        int take     = subarraySum[i] + Helper(subarraySum, k, i + k, cnt - 1);
        int not_take = Helper(subarraySum, k, i + 1, cnt);

        return t[i][cnt] = max(take, not_take);
    }

    void solve (vector<int>& subarraySum, int k, int i, int cnt, vector<int>& result) {
        if (cnt == 0) return;
        if (i >= subarraySum.size()) return;

        int take_i     = subarraySum[i] + Helper(subarraySum, k, i + k, cnt - 1);
        int not_take_i = Helper(subarraySum, k, i + 1, cnt); 

        if (take_i >= not_take_i) {
            result.push_back(i);
            solve(subarraySum, k, i + k, cnt - 1, result);
        } else {
            solve(subarraySum, k, i + 1, cnt, result);
        }
    }

    void slidingWindow(vector<int>& subarraySum, vector<int>& nums, int k) {
        int i = 0, j = 0, windowSum = 0;
        while (j < nums.size()) {
            windowSum += nums[j];
            if (j - i + 1 == k) {
                subarraySum.push_back(windowSum);
                windowSum -= nums[i];
                i ++;
            }
            j ++;
        }
    }

    // TC : O(N^3)
    // SC : O(1)
    vector<int> brute(vector<int>& nums, int k) {
        int n = nums.size();
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int idx1 = -1, idx2 = -1, idx3 = -1;
        for (int i = 0; i <= n - 3 * k; i ++) {
            // 1st subarray
            int val1 = accumulate(begin(nums) + i, begin(nums) + i + k, 0);
            for (int j = i + k; j <= n - 2 * k; j ++) {
                // 2nd subarray
                int val2 = accumulate(begin(nums) + j, begin(nums) + j + k, 0);
                for (int l = j + k; l <= n - k; l ++) {
                    // 3rd subarray
                    int val3 = accumulate(begin(nums) + l, begin(nums) + l + k, 0);
                    int total = val1 + val2 + val3;
                    if (total > sum1 + sum2 + sum3) {
                        sum1 = val1;
                        sum2 = val2;
                        sum3 = val3;
                        idx1 = i;
                        idx2 = j;
                        idx3 = l;
                    }
                }
            }
        }
        return {idx1, idx2, idx3};
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> optimal(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subarraySum;
        slidingWindow(subarraySum, nums, k);

        memset(t, -1, sizeof(t));

        vector<int> result;
        solve(subarraySum, k, 0, 3, result);
        return result;
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // return brute(nums, k);

        return optimal(nums, k);
    }
};
