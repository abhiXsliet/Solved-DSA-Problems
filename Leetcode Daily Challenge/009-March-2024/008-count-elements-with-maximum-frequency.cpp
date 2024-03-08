// https://leetcode.com/problems/count-elements-with-maximum-frequency/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(vector<int>& nums, int n) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        
        int res = 0;
        int mxFreq = INT_MIN;
        for (auto& it : mpp) {
            mxFreq = max(mxFreq, it.second);
        }
        
        for (auto& it : mpp) {
            if (it.second == mxFreq) {
                res += it.second;
            }
        }
        
        return res;
    }

    // TC : O(N)
    // SC : O(101)
    int solve_approach_2(vector<int>& nums, int n) {
        vector<int> freqCount(101, 0);

        int maxFreq = 0;
        for (int& num : nums) {
            freqCount[num] ++;
            maxFreq = max(maxFreq, freqCount[num]);
        }

        return count(begin(freqCount), end(freqCount), maxFreq) * maxFreq;
    }

    // TC : O(N)
    // SC : O(101) ~= O(1)
    int solve_approach_3(vector<int>& nums, int n) {
        vector<int> freq(101, 0);

        int maxFreq   = 0;
        int totalFreq = 0;

        for (int& num : nums) {
            freq[num] ++;

            int f = freq[num];

            if (f > maxFreq) {
                maxFreq   = f;
                totalFreq = maxFreq;
            }
            else if (f == maxFreq) {
                totalFreq += maxFreq;
            }
        }

        return totalFreq;
    }
public:
    int maxFrequencyElements(vector<int>& nums) {
        // return solve_approach_1(nums, nums.size());

        return solve_approach_2(nums, nums.size());

        // return solve_approach_3(nums, nums.size());
    }
};