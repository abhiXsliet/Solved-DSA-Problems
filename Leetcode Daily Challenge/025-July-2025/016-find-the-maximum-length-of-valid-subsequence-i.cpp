// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int approach_1(vector<int> &nums) {
        int n = nums.size();

        bool isEven = 0, isOdd = 0;
        int odds = 0, evens = 0, oddEven = 0, evenOdd = 0;
        // Try to only evens, only odds, take alternate even-odd or odd-even
        for (int i = 0; i < n; i ++) {
            if (nums[i] % 2) odds ++;
            else evens ++;
            
            if (isEven && nums[i] % 2 == 0) {
                isEven   = 0;
                oddEven += 1;
            } else if (!isEven && nums[i] % 2){
                oddEven += 1;
                isEven   = 1;
            }

            if (isOdd && nums[i] % 2) {
                evenOdd += 1;
                isOdd    = 0;
            } else if (!isOdd && nums[i] % 2 == 0) {
                evenOdd += 1;
                isOdd    = 1;
            }

        }
        
        return max({odds, evens, evenOdd, oddEven});
    }

    int approach_2(vector<int> &nums) {
        int n = nums.size();

        bool prevParity = nums[0] % 2;
        int odds  = (nums[0] % 2) ? 1 : 0;
        int evens = (nums[0] % 2) ? 0 : 1;
        int alterLen = 1;

        // Try to only evens, only odds, take alternate even-odd or odd-even
        for (int i = 1; i < n; i ++) {
            if (nums[i] % 2) odds ++;
            else evens ++;
            
            bool currParity = nums[i] % 2;
            if (currParity != prevParity) {
                alterLen   += 1;
                prevParity  = currParity;
            }
        }
        
        return max({odds, evens, alterLen});
    }
public:
    int maximumLength(vector<int>& nums) {
        // return approach_1(nums);
        return approach_2(nums); // a little clearer/concise code
    }
};