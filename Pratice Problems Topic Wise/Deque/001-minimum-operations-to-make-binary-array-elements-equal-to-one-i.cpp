// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

/* Similar problem : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/ */


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N) Where N = Size of the array nums
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        int k = 3;

        vector<int> isFlipped(n, 0);
        int flips = 0;
        int flipsFromThePasti = 0;

        for (int i = 0; i < n; i ++) {
            // *** Important : if the index [i - 1] is flipped then decrease the flipsFromThePasti cnt
            if (i >= k && isFlipped[i - k] == 1) {
                flipsFromThePasti -= 1;
            }

            if (flipsFromThePasti % 2 == nums[i]) {
                if (i + k > n) return -1;

                flips ++;
                flipsFromThePasti ++;
                isFlipped[i] = 1;
            }
        }

        return flips;
    }

    // TC : O(N) Where N = Size of the array nums
    // SC : O(1)
    int approach_2(vector<int>& nums) {
        int n = nums.size();
        int k = 3;

        int flips = 0;
        int flipsFromThePasti = 0;

        for (int i = 0; i < n; i ++) {
            // *** Important : if the index [i - 1] is flipped then decrease the flipsFromThePasti cnt
            if (i >= k && nums[i - k] == 7) {
                flipsFromThePasti -= 1;
            }

            if (flipsFromThePasti % 2 == nums[i]) {
                if (i + k > n) return -1;

                flips ++;
                flipsFromThePasti ++;
                nums[i] = 7;    
            }
        }

        return flips;
    }

    // TC : O(N) Where N = Size of the array nums
    // SC : O(K) ~= O(3) ~= O(1)
    int approach_3(vector<int>& nums) {
        int n = nums.size();
        int k = 3;

        int flips = 0;
        int flipsFromThePasti = 0;

        deque<int> isFlippedQue;

        for (int i = 0; i < n; i ++) {
            // *** Important : if the index [i - 1] is flipped then decrease the flipsFromThePasti cnt
            if (i >= k) {
                flipsFromThePasti -= isFlippedQue.front();
                isFlippedQue.pop_front();
            }

            if (flipsFromThePasti % 2 == nums[i]) {
                if (i + k > n) return -1;

                flips ++;
                flipsFromThePasti ++;
                isFlippedQue.push_back(1);  // 1 means : I have flipped
            } else {
                isFlippedQue.push_back(0);  // 0 means : I have not flipped
            }
        }

        return flips;
    }
public:
    int minOperations(vector<int>& nums) {
        // return approach_1(nums); // 

        // return approach_2(nums); // Used Input array as extra space 

        return approach_3(nums);    // Used Deque as extra space
    }
};