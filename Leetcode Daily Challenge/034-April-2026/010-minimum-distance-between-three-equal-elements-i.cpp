// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int minD = INT_MAX;

        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                for (int k = j + 1; k < n; k ++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        minD = min(minD, (abs(i - j) + abs(j - k) + abs(k - i)));
                    }
                }
            }
        }

        return minD == INT_MAX ? -1 : minD;
    }
};