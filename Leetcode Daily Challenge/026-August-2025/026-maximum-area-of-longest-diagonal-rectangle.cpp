// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagArea = 0;
        int maxRectArea = 0;

        for (vector<int> &dim : dimensions) {
            double diagArea = sqrt((dim[0] * dim[0]) + (dim[1] * dim[1]));
            int area = (dim[0] * dim[1]);

            if (diagArea > maxDiagArea) {
                maxDiagArea = diagArea;
                maxRectArea = area;
            } else if (diagArea == maxDiagArea && area > maxRectArea) {
                maxRectArea = area;
            }
        }

        return maxRectArea;
    }
};