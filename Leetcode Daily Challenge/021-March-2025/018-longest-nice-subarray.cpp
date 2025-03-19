// https://leetcode.com/problems/longest-nice-subarray/




#include <bits/stdc++.h>
using namespace std;

/*
- [a, b, c, d, x, u, v, w]: The result of the `&` (AND) operation between `x` and the elements in [a, ..., d] is zero if and only if there are no common set bits between `x` and any element preceding it (i.e., [a, ..., d]).  

- [a, b, c, d]: To track the set bits of all elements collectively, perform the `|` (OR) operation on each element.
*/

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int trackOr = 0;
        int i = 0, j = 0, maxLen = 0;
        while (j < n) {
            while (i < j && (trackOr & nums[j])) {
                trackOr ^= nums[i]; // Remove nums[i] from trackOr
                i ++;
            }

            trackOr |= nums[j];

            maxLen = max(maxLen, j - i + 1);
            j ++;
        }
        return maxLen;
    }
};