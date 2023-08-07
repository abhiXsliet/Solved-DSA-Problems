// https://leetcode.com/contest/weekly-contest-355/problems/largest-element-in-an-array-after-merge-operations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long sum = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > sum) {
                sum = 0;
            }
            
            sum += nums[i];
            ans = max(sum, ans);
        }
        return ans;
    }
};
