// https://leetcode.com/problems/contains-duplicate-ii/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    // TC = O(N*N) -> TLE
    // SC = O(1)
    bool brute(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {

                if(nums[i] == nums[j] && abs(i - j) <= k) 
                    return true;
                
            }
        }
        return false;
    }

    // TC = O(N)
    // SC = O(N)
    bool solve_better(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if( (mpp.find(nums[i]) != mpp.end()) && (i - mpp[nums[i]] <= k) ) {
                return 1;
            }
            mpp[nums[i]] = i;
        }
        return false;
    }

    // TC = O(N)
    // SC = O(N)
    // Sliding Window Approach
    bool solve_optimal(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        
        int left = 0;

        for(int right = 0; right < n; right++) {
            if(right - left > k) {
                mpp.erase(nums[left]);
                left += 1;
            }

            if( mpp.find(nums[right]) != mpp.end() ) {
                return 1;
            }
            mpp[nums[right]] = right;
        }
        return 0;
    }

public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // return brute(nums, k);

        // return solve_better(nums, k);

        return solve_optimal(nums, k);
    }
};