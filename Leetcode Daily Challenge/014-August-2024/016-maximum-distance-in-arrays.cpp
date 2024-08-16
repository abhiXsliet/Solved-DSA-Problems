// https://leetcode.com/problems/maximum-distance-in-arrays/




#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();

        int result = 0;
        for (int i = 1; i < arrays.size(); i ++) {
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result = max({result, abs(currMin - maxi), abs(currMax - mini)});

            maxi   = max(maxi, currMax);
            mini   = min(mini, currMin);
        }
        return result;
    }
};