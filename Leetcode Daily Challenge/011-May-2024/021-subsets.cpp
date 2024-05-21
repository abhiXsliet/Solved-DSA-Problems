// https://leetcode.com/problems/subsets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(2^N * N)
    // SC = O(1)
    vector<vector<int>> solve_better(vector<int>& nums) {
        vector<vector<int>> ans;
        int power = pow(2, nums.size());

        for (int c = 0; c < power; c++) {
            vector<int> temp;
            for (int i = 0; i < nums.size(); i++) {
                int power2 = pow(2, i);
                
                if (c & power2) {
                    temp.push_back(nums[i]);
                }   
            }
            ans.push_back(temp);
        }
        return ans;
    }

    // TC = O(2^N)
    // SC = O(N)
    void generateSubsets(vector<int>& nums, vector<int>& totalSubsets, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {
            ans.push_back(totalSubsets);
            return;
        }

        // exclude
        generateSubsets(nums, totalSubsets, ans, index+1);

        totalSubsets.push_back(nums[index]);

        // include 
        generateSubsets(nums, totalSubsets, ans, index+1);

        // backtrack
        totalSubsets.pop_back();
    }

    vector<vector<int>> solve_optimal(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> totalSubsets;
        int index = 0;
        generateSubsets(nums, totalSubsets, ans, index);
        return ans;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // return solve_better(nums);

        return solve_optimal(nums);
    }
};