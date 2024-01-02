// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2) -> At Worst Freq == 1 Of each 'N' Numbers
    // SC : O(N)
    vector<vector<int>> solve_approach_1(vector<int>& nums, int n) {
        vector<vector<int>> result;

        unordered_map<int, int> mpp;
        for (auto& num : nums) {
            mpp[num] ++;
        }
        
        int maxFreq = 0;
        for (auto& val: mpp) {
            maxFreq = max(maxFreq, val.second);
        }

        for (int freq = 1; freq <= maxFreq; freq++) {
            vector<int>temp;
            for (auto& val : mpp) {
                if (val.second >= freq) {
                    temp.push_back(val.first);
                }
            }
            result.push_back(temp);
        }

        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<vector<int>> solve_approach_2(vector<int>& nums, int n) {
        vector<vector<int>> result;

        vector<int> count(n+1, 0);

        for (int i = 0; i < n; i++) {
            int freq = count[nums[i]];

            if (freq == result.size()) {
                // add one more row
                result.push_back({});
            }

            // In 'freq'th row push the current element 
            result[freq].push_back(nums[i]);
            
            // Increase the count of current element
            count[nums[i]]++;
        }
        return result;
    }
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // return solve_approach_1(nums, nums.size());

        return solve_approach_2(nums, nums.size());
    }
};