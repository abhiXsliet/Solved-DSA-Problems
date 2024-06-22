// https://leetcode.com/problems/count-number-of-nice-subarrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> nums, int k, int n) {
        int no_of_subarrays = 0;
        
        // map store the {prefixSum, count of prefixSum}
        unordered_map<int, int> mpp;
        mpp[0]     = 1;
        int oddCnt = 0;
        
        for (int i = 0; i < n; i++) {
            oddCnt += (nums[i] % 2);    // if even add 1 otherwise 0
            no_of_subarrays += mpp[oddCnt - k];
            mpp[oddCnt]++;
        }
        return no_of_subarrays;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> nums, int k, int n) {
        vector<int> freq(n+1);
        freq[0] = 1;

        int oddCnt          = 0;
        int no_of_subArrays = 0;

        for (int num : nums) {
            oddCnt += (num & 1);
            if (oddCnt - k >= 0) 
                no_of_subArrays += freq[oddCnt - k];
            freq[oddCnt] ++;
        }

        return no_of_subArrays;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int> nums, int k, int n) {
        int prevCnt  = 0;
        int oddCnt   = 0;
        int result   = 0;
        int l = 0, r = 0;

        while (r < n) {
            if (nums[r] % 2 != 0) {
                oddCnt += 1;
                prevCnt = 0; 
            }

            while (oddCnt == k) {
                prevCnt += 1;

                if (l <= r && nums[l] % 2 != 0) {
                    oddCnt --;
                }
                l += 1;
            }

            result += prevCnt;
            r ++;
        }
        return result;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // return approach_1(nums, k, nums.size());     // Storing Prev oddCnt in Hastable

        // return approach_2(nums, k, nums.size());     // Storing Prev oddCnt freq in vector

        return approach_3(nums, k, nums.size());     // Sliding Window by keeping prev removed elements    
    }
};