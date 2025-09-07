// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(1)
    int approach_1(vector<vector<int>> &points) {
        int n = points.size();
        int result = 0;

        for (int i = 0; i < n; i ++) {

            int x1 = points[i][0], y1 = points[i][1];

            for (int j = 0; j < n; j ++) {

                if (j == i) continue;
                int x2 = points[j][0], y2 = points[j][1];

                // upper left point
                if (x2 <= x1 && y2 >= y1) {

                    bool isAnyPt = false;
                    for (int k = 0; k < n; k ++) {
                        
                        if (k == i || k == j) continue;
                        int x3 = points[k][0], y3 = points[k][1];
                        
                        if (x3 >= x2 && x3 <= x1 && y3 >= y1 && y3 <= y2) {
                            isAnyPt = true;
                            break;
                        }
                    }

                    if (!isAnyPt) result += 1;

                }
            }
        }

        return result;
    }

    // TC : O(N^2)
    // SC : O(1)
    int approach_2(vector<vector<int>> &points) {
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
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // return approach_1(points);
        return approach_2(points);
    }
};