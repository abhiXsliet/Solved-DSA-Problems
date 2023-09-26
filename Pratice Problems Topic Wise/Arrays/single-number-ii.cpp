// https://leetcode.com/problems/single-number-ii/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC = O( N * N )
    int solve_brute(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool isUnique = 1;
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    isUnique = 0;
                    break;
                }
            }

            if(isUnique) {
                return nums[i];
            }
        }
        return 0;
    }

    // TC = O(N * log(N)) where log(N) <= 32 (since N <= INT_MAX)
    int solve_better_1(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        
        // Edge Cases
        if (n == 1) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n -1];

        for (int i = 1; i < n; i+=3) {
            if (nums[i - 1] != nums[i]) 
                return nums[i - 1];
        }
        return 0;
    }

    // TC = O(32 * N) for all cases (worst, average, best) which is not equal to O(N)
    int solve_better_2(vector<int>& nums) {
        int n = nums.size();

        int mask = 1, ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mask & nums[j]) 
                    cnt ++;
            }

            if (cnt % 3 != 0) 
                ans += mask;
                
            mask <<= 1;
        }
        return ans;
    }

    // TC = O( N )
    int solve_optimal(vector<int>& nums) {
        int n = nums.size();

        // Step-1 : Initialize variable ones and twos
        // ones stores if an element appears one time
        // twos stores if the element appears 2nd times
        // elements appeared 3rd times will neither stored in ones not in twos

                                    // 2  2  3  2
        int ele_appears_ones = 0;   // 2  0  1  3 --> 3 is the element which appeared only once
        int ele_appears_twos = 0;   // 0  2  0  0

        // Step-2: do calculations
        for (int i = 0; i < n; i++) {
            ele_appears_ones ^= nums[i];
            ele_appears_ones &= (~ele_appears_twos);

            ele_appears_twos ^= nums[i];
            ele_appears_twos &= (~ele_appears_ones);
        }
        return ele_appears_ones;
    }
public:
    int singleNumber(vector<int>& nums) {
        // return solve_brute(nums);

        // return solve_better_1(nums);

        // return solve_better_2(nums);

        return solve_optimal(nums);
    }
};