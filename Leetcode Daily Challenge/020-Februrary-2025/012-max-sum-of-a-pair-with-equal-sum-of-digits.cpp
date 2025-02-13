// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int maxSum = -1;
        for (int &num : nums) {
            int sumDigits = getDigitSum(num);
            int sum = 0;

            if (!mpp.count(sumDigits)) { 
                mpp[sumDigits] = num;
            } else {
                sum += mpp[sumDigits];
                sum += num;
                if (mpp[sumDigits] < num)
                    mpp[sumDigits] = num;
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    // TC : O(N)
    // SC : O(82) const. size array instead of mpp
    int approach_2(vector<int>& nums) {
        int n = nums.size();
        int mpp[82] = {0};
        int maxSum = -1;
        for (int &num : nums) {
            int sumDigits = getDigitSum(num);
            int sum = 0;

            if (!mpp[sumDigits]) { 
                mpp[sumDigits] = num;
            } else {
                sum += mpp[sumDigits];
                sum += num;
                if (mpp[sumDigits] < num)
                    mpp[sumDigits] = num;
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
public:
    int maximumSum(vector<int>& nums) {
        // return approach_1(nums); 
        return approach_2(nums);   
    }
};