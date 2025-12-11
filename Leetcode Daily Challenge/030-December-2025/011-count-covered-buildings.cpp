// https://leetcode.com/problems/count-covered-buildings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // maps:
        // for each x -> (minY, maxY)
        unordered_map<int, pair<int,int>> xToMinMaxY;
        // for each y -> (minX, maxX)
        unordered_map<int, pair<int,int>> yToMinMaxX;

        // initialize maps with extreme values
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            if (!xToMinMaxY.count(x)) xToMinMaxY[x] = {INT_MAX, INT_MIN};
            if (!yToMinMaxX.count(y)) yToMinMaxX[y] = {INT_MAX, INT_MIN};

            // update min/max for the column x (we store Y range)
            xToMinMaxY[x].first  = min(xToMinMaxY[x].first, y); // minY
            xToMinMaxY[x].second = max(xToMinMaxY[x].second, y); // maxY

            // update min/max for the row y (we store X range)
            yToMinMaxX[y].first  = min(yToMinMaxX[y].first, x); // minX
            yToMinMaxX[y].second = max(yToMinMaxX[y].second, x); // maxX
        }

        int result = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto prY = xToMinMaxY[x]; // (minY, maxY) for this x
            auto prX = yToMinMaxX[y]; // (minX, maxX) for this y

            int minY = prY.first, maxY = prY.second;
            int minX = prX.first, maxX = prX.second;

            // strictly inside vertically and horizontally
            if (minY < y && y < maxY && minX < x && x < maxX) result++;
        }
        return result;
    }
};