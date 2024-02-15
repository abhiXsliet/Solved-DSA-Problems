// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N * log(N)) Where N = nums.size()
    // SC : O(1)
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        long long ans = -1;
        long long cum_sum = 0;
        for (int num : nums) {
            if (num < cum_sum) {
                ans = cum_sum + num;
            }
            cum_sum += num;
        }
        return ans;
    }
};