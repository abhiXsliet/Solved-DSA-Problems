// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        int flipsCntFromPastFori = 0;

        vector<bool> isFlipped(n, 0);

        for (int i = 0; i < n; i ++) {
            // *** Important : check if the index [i - k] is flipped or not?
            if (i >= k && isFlipped[i - k] == 1) {
                flipsCntFromPastFori  -= 1;
            }

            if (flipsCntFromPastFori % 2 == nums[i]) {
                if (i + k > n) return -1;

                flips ++;
                flipsCntFromPastFori ++;
                isFlipped[i] = 1;
            }
        }

        return flips;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        int flipsCntFromPastFori = 0;

        for (int i = 0; i < n; i ++) {
            // ***Important to note 
            if (i >= k && nums[i - k] == 7) {   
                flipsCntFromPastFori  -= 1;
            }

            if (flipsCntFromPastFori % 2 == nums[i]) {
                if (i + k > n) return -1;

                flips ++;
                flipsCntFromPastFori ++;
                nums[i] = 7;
            }
        }

        return flips;
    }

    // TC : O(N)
    // SC : O(k)
    int approach_3(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        int flipsCntFromPastFori = 0;

        deque<int> isFlippedQue;

        for (int i = 0; i < n; i ++) {
            if (i >= k) {
                // [i - k] is flipped or not is stored at the front of the deque
                flipsCntFromPastFori  -= isFlippedQue.front();  
                isFlippedQue.pop_front();
            }

            if (flipsCntFromPastFori % 2 == nums[i]) {
                if (i + k > n) return -1;

                flips ++;
                flipsCntFromPastFori ++;
                isFlippedQue.push_back(1);   // pushing 1 : since i have flipped index i
            } else {
                isFlippedQue.push_back(0);   // pushing 0 : since no flipped is done at index i
            }
        }

        return flips;
    }
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // return approach_1(nums, k);     

        // return approach_2(nums, k);     // same as approach_1 but modifying input array

        return approach_3(nums, k);        // Not Modified Input Array, used deque instead
    }
};