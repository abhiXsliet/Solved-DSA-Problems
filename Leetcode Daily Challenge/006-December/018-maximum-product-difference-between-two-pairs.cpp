// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    int solve_brute(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        return (nums[n-1]*nums[n-2]) - (nums[0]*nums[1]);
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(vector<int>& nums) {
        int n = nums.size();

        int largest      = INT_MIN;
        int sec_largest  = INT_MIN;

        int smallest     = INT_MAX;
        int sec_smallest = INT_MAX;

        for (int num : nums) {
            if (num > largest) {
                sec_largest = largest;
                largest     = num;
            } else 
                sec_largest = max(sec_largest, num);

            if (num < smallest) {
                sec_smallest = smallest;
                smallest     = num;
            } 
            else 
                sec_smallest = min(sec_smallest, num);
        }

        return largest*sec_largest - smallest*sec_smallest;
    }
public:
    int maxProductDifference(vector<int>& nums) {
        // return solve_brute(nums);

        return solve_optimal(nums);
    }
};