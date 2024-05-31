// https://leetcode.com/problems/single-number-iii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    vector<int> solve_brute(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;
        for (int i = 0; i < n; i++) {
            bool isUnique = 1;
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    isUnique = 0;
                }
            }

            if (isUnique) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }

    // TC : O(N * log(N))
    // SC : O(1)
    vector<int> solve_better(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        sort (nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (i == 0) { // handle starting element
                if (nums[i] != nums[i + 1]) {
                    result.push_back(nums[i]);
                }
            }
            else if (i == n - 1) { // handle last element
                if (nums[i] != nums[i - 1]) {
                    result.push_back(nums[i]);
                }
            }
            else { // handle middle case
                if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
                    result.push_back(nums[i]);
                }
            }
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> solve_optimal(vector<int>& nums) {
        int n = nums.size();

        long xor_all = 0;
        for(int i = 0; i < n; i++) {
            xor_all ^= nums[i];
        }
        
        // create a mask where the rightmost bit is set
        long rightmost_set_bit = xor_all & -xor_all;
        
        int groupA = 0, groupB = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] & rightmost_set_bit) {
                groupA ^= nums[i];
            } else {
                groupB ^= nums[i];
            }
        }
        
        return vector<int>{groupA, groupB};
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
        // return solve_brute(nums);

        // return solve_better(nums);

        return solve_optimal(nums);
    }
};