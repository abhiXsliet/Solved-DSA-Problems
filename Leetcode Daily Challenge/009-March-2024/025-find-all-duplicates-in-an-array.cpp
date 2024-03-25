// https://leetcode.com/problems/find-all-duplicates-in-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    vector<int> solve_1(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        for(auto& i: map) {
            if(i.second > 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> solve_2(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int index = abs(nums[i])-1;
            int element = nums[index];
            if(element < 0)
                ans.push_back(abs(nums[i]));

            nums[index] = nums[index] * (-1);
        }
        return ans;
    }
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // return solve_1(nums);

        return solve_2(nums);
    }
};