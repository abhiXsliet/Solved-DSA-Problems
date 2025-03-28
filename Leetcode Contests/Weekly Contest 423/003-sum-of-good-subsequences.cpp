// https://leetcode.com/problems/sum-of-good-subsequences/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    // count[i] = count of good subseq. considering value i as the ending
    // sum[i]   = sum   of good subseq. considering value i as the ending
    vector<long> sum, count;
    const int max_val = 1e5;
    const int M = 1e9 + 7;

    int solve(vector<int> &nums) {
        for (int num : nums) {
            count[num] = (1 + count[num]) % M;  // count of currEle num
            sum[num]   = (num + sum[num]) % M;  // sum of currEle num

            if (num - 1 >= 0) {
                count[num] = (count[num] + count[num - 1]) % M; // count of (currEle - 1)
                sum[num]   = (sum[num] + sum[num - 1] + (count[num - 1] * num) % M) % M;    // sum(currEle - 1) + currEle contribution to all count of prev.(currEle - 1) good subseq
            }

            if (num + 1 <= max_val) {
                count[num] = (count[num] + count[num + 1]) % M; // count of (currEle + 1)
                sum[num]   = (sum[num] + sum[num + 1] + (count[num + 1] * num) % M) % M;    // sum(currEle + 1) + currEle contribution to all count of next(currEle + 1) good subseq 
            }
        }
        long ans = 0;
        for (int i = 0; i <= max_val; i ++) {
            ans = (ans + sum[i]) % M;
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &nums) {
        sum   = vector<long> (max_val + 1, 0);
        count = vector<long> (max_val + 1, 0);
        return solve(nums);
    }
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        n = nums.size();

        return approach_1(nums);
    }
};