// https://leetcode.com/problems/subarrays-with-k-different-integers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int getSubArrayCnt(vector<int>& nums, int n, int k) {
        unordered_map<int, int> freq;
        int i = 0, j = 0, cntSubArray = 0;
        
        while(j < n) {
            freq[nums[j]] ++;

            while (i <= j && freq.size() > k) {
                freq[nums[i]] --;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i ++;
            }
            cntSubArray += (j - i + 1);   // freq.size() <= k
            j ++;
        }

        return cntSubArray;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(vector<int>& nums, int k) {
        int n = nums.size();
        // for 'k' size of sliding window : gives cnt of k-distinct elements subarray
        int totalSubArrayCnt = getSubArrayCnt(nums, n, k);  
        // for 'k-1' size of sliding window : gives cnt of (k-1)-distinct elements subarray
        int subArrayCnt      = getSubArrayCnt(nums, n, k - 1);

        return totalSubArrayCnt - subArrayCnt;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_approach_2(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        int prev_i      = 0;    // it will track the largest subarray from prev_i to j
        int cntSubArray = 0;
        unordered_map<int, int> freq;

        while (j < n) {
            freq[nums[j]] ++;

            while(freq.size() > k) {
                freq[nums[i]] --;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i ++;
                prev_i = i;
            }

            // smallest valid subArray ending at j and starting at i
            while (freq[nums[i]] > 1) {
                freq[nums[i]] --;
                i ++;
            }

            if (freq.size() == k) {
                cntSubArray += 1;             // smallest subArray 
                cntSubArray += i - prev_i;    // smallest subArray can be elongated to the prev_i index
            }
            j ++;
        }

        return cntSubArray;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // return solve_approach_1(nums, k);

        return solve_approach_2(nums, k);   // ONE PASS
    }
};