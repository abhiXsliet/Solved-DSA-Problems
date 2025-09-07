// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N^2)
    // SC : O(1)
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto cmp = [&](auto p1, auto p2) {
            if (p1[0] == p2[0]) {
                return p1[1] > p2[1];
            }
            return p1[0] <= p2[0];
        };

        sort(begin(points), end(points), cmp);

        int result = 0;

        for (int i = 0; i < n; i ++) {
            int x1 = points[i][0], y1 = points[i][1];
            
            int maxY = INT_MIN;
            // get the lower right point
            for (int j = i + 1; j < n; j ++) {

                int x2 = points[j][0], y2 = points[j][1];

                if (y2 > y1) continue;

                if (maxY < y2) {
                    maxY = y2;
                    result += 1;
                }
            }
        }

        return result;
    }
};