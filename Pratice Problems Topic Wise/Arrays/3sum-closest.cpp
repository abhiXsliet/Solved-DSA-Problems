// https://leetcode.com/problems/3sum-closest/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * N * N)
    // SC = O(1)
    int solve_brute(vector<int>& nums, int n, int tar) {
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n-2; i++) {
            for (int j = i + 1; j < n-1; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    // check and update closest with abs val of tar, sum, closest
                    if (abs(tar - sum) < abs(tar - closest)) {
                        closest = sum;
                    }
                }
            }
        }
        return closest;
    }

    // TC = O(N*N)
    // SC = O(1)
    int solve_optimal(vector<int>& nums, int n, int tar) {
        // O(N * log(N))
        sort(begin(nums), end(nums));

        // nums[0] + nums[1] + nums[2]
        int closest = accumulate(begin(nums), begin(nums) + 3, 0);

        // fix each number of arr and find their respective pair numbers
        for (int i = 0; i < n - 2; i++) {

            // two pointer to find the rest two elements
            int left  = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // update the closest if more close val if found than its prev val
                if (abs(tar - sum) < abs(tar - closest)) {
                    closest = sum;
                }
                else if (sum < tar) left++;
                else right--;
            }
        }

        return closest;
    }
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // return solve_brute(nums, nums.size(), target);

        return solve_optimal(nums, nums.size(), target);
    }
};