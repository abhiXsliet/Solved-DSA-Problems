// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();

        sort(begin(points), end(points));

        int res = 0;
        for (int i = 0; i < n-1; i++) {
            int width = points[i+1][0] - points[i][0];
            res = max(res, width);
        }

        return res;
    }
};