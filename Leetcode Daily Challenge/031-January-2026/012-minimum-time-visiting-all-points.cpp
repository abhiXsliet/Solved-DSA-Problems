// https://leetcode.com/problems/minimum-time-visiting-all-points/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        for (int i = 0; i < n - 1; i ++) {
            int dx = abs(points[i][0] - points[i + 1][0]);
            int dy = abs(points[i][1] - points[i + 1][1]);
            cout << dx << " " << dy << endl;
            result += max(dx, dy);
        }
        return result;
    }
};