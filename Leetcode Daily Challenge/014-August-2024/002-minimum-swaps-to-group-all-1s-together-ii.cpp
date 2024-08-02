// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int brute(vector<int>& nums, int n) {
        int cntOnes = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 1)
                cntOnes ++;
        }

        int minSwaps = INT_MAX;
        for (int i = 0; i < n; i ++) {
            int swap = 0;
            for (int j = i; j < cntOnes + i; j ++) {
                if (nums[j % n] == 0) {
                    swap ++;
                }
            }
            minSwaps = min(minSwaps, swap);
        }
        return minSwaps;
    }

    // TC : O(N)
    // SC : O(1)
    int better(vector<int>& nums, int n) {
        int cntOnes = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 1)
                cntOnes ++;
        }

        int swaps = 0;
        int i = 0, j = 0;
        while (j < cntOnes) {
            if (nums[j] == 0)
                swaps ++;
            j ++;
        }

        int minSwaps = INT_MAX;
        minSwaps     = min(minSwaps, swaps);
        while (i < n) {
            if (j - i + 1 >= cntOnes) {
                if (nums[i] == 0) 
                    swaps --;
                i ++;
            }
            if (nums[j % n] == 0) {
                swaps ++;
            }
            minSwaps = min(minSwaps, swaps);
            j ++;
        }
        return minSwaps;
    }

    // TC : O(N)
    // SC : O(N)
    int optimal(vector<int>& nums, int n) {
        int cntOnes = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 1)
                cntOnes ++;
        }

        int swaps = 0;
        int minSwaps = INT_MAX;
        int i = 0, j = 0;

        while (i < n) {
            while (j < cntOnes + i) {
                if (nums[j] == 0)
                    swaps ++;
                j ++;
            }

            if (j - i + 1 >= cntOnes) {
                if (nums[i] == 0) 
                    swaps --;
                i ++;
            }
            
            if (nums[j % n] == 0) {
                swaps ++;
            }

            minSwaps = min(minSwaps, swaps);
            j ++;
        }
        return minSwaps;
    }
public:
    int minSwaps(vector<int>& nums) {
        // return brute(nums, nums.size());

        // return better(nums, nums.size());   

        return optimal(nums, nums.size());  // ONE PASS
    }
};