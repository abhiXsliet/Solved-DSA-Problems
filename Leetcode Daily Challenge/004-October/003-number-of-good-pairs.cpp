// https://leetcode.com/problems/number-of-good-pairs/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve_approach_1(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i<n-1; i++) {
            int num = nums[i];
            
            for(int j = i+1; j<n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
        }
        
        return count;
    }

    int solve_approach_2(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        for(auto &it : mp) {
            
            int count = it.second;
            result += (count * (count-1))/2;
            
        }
        
        return result;
    }

    int solve_approach_3(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            result += mp[num]++;
        }
      
        return result;
    }
public:
    int numIdenticalPairs(vector<int>& nums) {
        // return solve_approach_1(nums);

        // return solve_approach_2(nums);

        return solve_approach_3(nums);
    }
};