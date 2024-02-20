// https://leetcode.com/problems/missing-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve(vector<int>& nums) {
        //missing no. lies b/w [0, nums.size()]
        int n    = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return (n * (n + 1) / 2) - sum;
    }
public:
    int missingNumber(vector<int>& nums) {
        return solve(nums);
    }
};