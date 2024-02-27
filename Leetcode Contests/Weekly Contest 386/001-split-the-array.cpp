// https://leetcode.com/contest/weekly-contest-386/problems/split-the-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    bool solve_1(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num] ++;
        }
        
        for (auto& it : mpp) {
            if (it.second > 2) return false;
        }
        return true;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    bool solve_2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == nums[i + 2]) return false;
        }
        return true;
    }
public:
    bool isPossibleToSplit(vector<int>& nums) {
        // return solve_1(nums);
        
        return solve_2(nums);
    }
};