// https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int M = 1e9 + 7;
    int t[201][201][201];
    int solve(vector<int> &nums, int i, int first, int second) {
        if (i == nums.size()) {
            bool bothNonEmpty = first != 0 && second != 0;
            bool checkEqualGcd = (first == second);

            return bothNonEmpty && checkEqualGcd;
        }

        if (t[i][first][second] != -1) return t[i][first][second];

        int skip  = solve(nums, i + 1, first, second);
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);
        int take2 = solve(nums, i + 1, first, __gcd(nums[i], second));

        return t[i][first][second] = (0LL + skip + take1 + take2) % M;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
    }
};