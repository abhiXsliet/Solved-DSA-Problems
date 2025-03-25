// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> getMerged(vector<vector<int>> &coordinates) {
        sort(begin(coordinates), end(coordinates));
        vector<vector<int>> result;
        for (vector<int> interval : coordinates) {
            if (result.empty() || result.back()[1] <= interval[0]) {
                result.push_back(interval);
            } else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }

    int getMergedOptimized(vector<vector<int>> &coordinates) {
        sort(begin(coordinates), end(coordinates));
        int start = coordinates[0][0], end = coordinates[0][1];
        int count = 1;
        for (int i = 1; i < coordinates.size(); i ++) {
            int l = coordinates[i][0], r = coordinates[i][1];
            if (l >= start && l < end) {
                end = max(end, r);
            } else {
                count ++;
                end   = r;
                start = l;
            }
        }
        return count >= 3;
    }

    // TC : O(N*log(N)) Where N = rectangles.size()
    // SC : O(N) 
    bool approach_1(int n, vector<vector<int>> &rectangles) {
        vector<vector<int>> xCoor, yCoor;
        for (vector<int> rect : rectangles) {
            int sx = rect[0], sy = rect[1];
            int ex = rect[2], ey = rect[3];
            xCoor.push_back({sx, ex});
            yCoor.push_back({sy, ey});
        }

        xCoor = getMerged(xCoor);
        yCoor = getMerged(yCoor);
        
        return xCoor.size() >= 3 || yCoor.size() >= 3;
    }

    // TC : O(N*log(N)) Where N = rectangles.size()
    // SC : O(N) 
    bool approach_2(int n, vector<vector<int>> &rectangles) {
        vector<vector<int>> xCoor, yCoor;
        for (vector<int> rect : rectangles) {
            int sx = rect[0], sy = rect[1];
            int ex = rect[2], ey = rect[3];
            xCoor.push_back({sx, ex});
            yCoor.push_back({sy, ey});
        }
        
        return getMergedOptimized(xCoor) || getMergedOptimized(yCoor);
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // return approach_1(n, rectangles);
        return approach_2(n, rectangles);
    }
};