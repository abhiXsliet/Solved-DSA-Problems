// https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    // TC : O(N*L) Where N = Size of array 
    // SC : O(L)   Where L = Maximum Length of any individual element of nums
    ll approach_1(vector<int>& nums) { 
        int n = nums.size();

        ll ans = 0;
        map<int, unordered_map<int, int>> mpp; // {indices, {number : cnt}}
        
        string firstEl = to_string(nums[0]);
        for (int j = 0; j < firstEl.length(); j ++) {
            mpp[j][firstEl[j] - '0'] ++;
        }

        for (int i = 1; i < n; i ++) {
            string secondEl = to_string(nums[i]);

            for (int j = 0; j < secondEl.length(); j ++) {
                // count of all previous elements chars at respective index
                int cntOfDigit = mpp[j][secondEl[j] - '0']; 

                ll sum = 0;
                for (auto& it : mpp[j]) {
                    sum += it.second;
                }

                ans += sum - cntOfDigit;
                mpp[j][secondEl[j] - '0'] ++;
            }
        }
        return ans;
    }
public:
    ll sumDigitDifferences(vector<int>& nums) {
        return approach_1(nums);
    }
};