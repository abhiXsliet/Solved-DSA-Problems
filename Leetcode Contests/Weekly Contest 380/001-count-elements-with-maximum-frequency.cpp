// https://leetcode.com/contest/weekly-contest-380/problems/count-elements-with-maximum-frequency/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
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
};