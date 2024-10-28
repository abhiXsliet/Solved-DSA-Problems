// https://leetcode.com/problems/longest-square-streak-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int result = 0;
        for (int &num : nums) {
            int subLen = 0;
            long currNum = num;
            while (currNum <= 1e5 && st.count(currNum)) {   // O(5) at worst : 2, 4, 16, 256, 65536, 4294967296
                subLen ++;
                currNum *= currNum;
            }
            result = max(result, subLen);
        }
        return result < 2 ? -1 : result;
    }
};