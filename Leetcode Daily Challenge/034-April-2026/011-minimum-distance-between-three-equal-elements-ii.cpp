// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i ++) {
            mpp[nums[i]].push_back(i);
        }

        int minD = INT_MAX;
        for (auto &[num, vec] : mpp) {
            int len = vec.size();
            if (len > 2) {
                int i = 0, j = 1, k = 2;
                while (k < len) {
                    minD = min(minD, (abs(vec[i] - vec[j]) + abs(vec[j] - vec[k]) + abs(vec[k] - vec[i])));
                    i ++, j++, k ++;
                }
            }
        }
        return minD == INT_MAX ? -1 : minD;
    }
};