// https://leetcode.com/contest/biweekly-contest-137/problems/find-the-power-of-k-size-subarrays-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 1 || k == 1) return nums;

        int i = 0, j = i + 1;
        vector<int> result(n - k + 1, -1);
        int conti    = 0;   // count of continuous elements
        int disConti = 0;   // count of discontinuous elements
        
        while (j < n) {
            if (nums[j] - 1 != nums[j - 1]) 
                disConti ++;
            else 
                conti ++;

            if (j - i + 1 == k) {
                if (disConti) 
                    result[i] = -1;
                else 
                    result[i] = nums[j];

                i ++;
                if (nums[i] - 1 != nums[i - 1]) 
                    disConti --;
                else 
                    conti --;
            }
            j ++;
        }
        return result;
    }
};