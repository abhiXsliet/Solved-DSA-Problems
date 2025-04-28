// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N)
    // SC : O(1)
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        ll cntSubArr = 0, sum = 0;
        int i = 0, j = 0;
        while (j < n) {
            sum += nums[j];
            while (i < j && (sum * (j - i + 1)) >= k) {
                sum -= nums[i];
                i ++;
            }
            if ((sum * (j - i + 1)) < k)
                cntSubArr += (j - i + 1);
            j ++;
        }
        return cntSubArr;
    }
};