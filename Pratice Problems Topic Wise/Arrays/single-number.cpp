// https://leetcode.com/problems/single-number/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * N)
    int solve_brute(vector<int>& nums) {
        int n   = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            bool isUnique = true;
            
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    isUnique = false;
                    break;
                }
            }

            if(isUnique) {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }

    // TC = O(N * log(N))
    int solve_better(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Edge Cases
        if (n == 1) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        for (int i = 1; i < n; i+=2) {
            if (nums[i - 1] != nums[i])
                return nums[i - 1];
        }

        return 0;
    }

    // TC = O(N)
    int solve_optimal(vector<int>& nums) {
        int n = nums.size();
        int uniqueNo = 0;

        for (int& num : nums) {
            uniqueNo = uniqueNo ^ num;
        }
        
        return uniqueNo;
    }
public:
    int singleNumber(vector<int>& nums) {
        // return solve_brute(nums);

        return solve_better(nums);

        // return solve_optimal(nums);
    }
};