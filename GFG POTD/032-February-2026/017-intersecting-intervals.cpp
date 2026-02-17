// https://www.geeksforgeeks.org/problems/intersecting-intervals/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int overlapInt(vector<vector<int>> &arr) {

        int maxEnd = 0;
        for (auto &it : arr)
            maxEnd = max(maxEnd, it[1]);

        vector<int> timeline(maxEnd + 2, 0);

        for (auto &it : arr) {
            timeline[it[0]]++;
            timeline[it[1] + 1]--;
        }

        int maxOverlap = 0, curr = 0;
        for (int i = 0; i <= maxEnd; i++) {
            curr += timeline[i];
            maxOverlap = max(maxOverlap, curr);
        }

        return maxOverlap;
    }
};