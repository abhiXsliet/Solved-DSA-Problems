// https://leetcode.com/problems/contiguous-array/
// same pattern problems : 560, 930, 1074


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    // convert all 0's into -1's and add the summation into the map
    int solve_way_1(vector<int>& nums, int n) {
        unordered_map<int, int> mpp;
        mpp[0] = 0; // {sum, index}

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) 
                nums[i] = -1;
        }

        int maxSubarryLen = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mpp.find(sum) == mpp.end())
                mpp[sum] = i;
            else {
                maxSubarryLen = max(maxSubarryLen, i - mpp[sum] + 1);
            }
        }
        return maxSubarryLen % 2 == 0 ? maxSubarryLen : maxSubarryLen - 1;
    }

    // TC : O(N)
    // SC : O(N)
    // convert all 0's into -1's and add the summation into the map
    int solve_way_2(vector<int>& nums, int n) {
        unordered_map<int, int> mpp{{0, -1}};

        int maxSubarryLen = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            
            if (mpp.count(sum)) 
                maxSubarryLen = max(maxSubarryLen, i - mpp[sum]);
            else 
                mpp[sum] = i;
        }
        return maxSubarryLen;
    }
public:
    int findMaxLength(vector<int>& nums) {
        // return solve_way_1(nums, nums.size());
        
        return solve_way_2(nums, nums.size());
    }
};