// https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(begin(points), end(points));
        int i = 0, j = 0, n = points.size(), rectangles = 0;
        while (i < n) {
            while (j < n && points[j][0] - points[i][0] <= w) {
                j ++;
            }
            rectangles ++;
            i = j;
        }
        return rectangles;
    }
};