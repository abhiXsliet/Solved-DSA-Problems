// https://leetcode.com/contest/weekly-contest-386/problems/find-the-largest-area-of-square-inside-two-rectangles/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    ll calArea(vector<int>& r1_bottomLeft, vector<int>& r1_topRight, vector<int>& r2_bottomLeft, vector<int>& r2_topRight) {
        ll xBottomLeft = max(r1_bottomLeft[0], r2_bottomLeft[0]);
        ll yBottomLeft = max(r1_bottomLeft[1], r2_bottomLeft[1]);
        
        ll xTopRight   = min(r1_topRight[0], r2_topRight[0]);
        ll yTopRight   = min(r1_topRight[1], r2_topRight[1]);
        
        if (xTopRight > xBottomLeft && yTopRight > yBottomLeft) {
            ll xSide = xTopRight - xBottomLeft;
            ll ySide = yTopRight - yBottomLeft;
            ll side = min(xSide, ySide);

            return side * side;
        }
        return 0;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    ll way_1(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                maxArea = max(maxArea, calArea(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
            }
        }
        return maxArea;
    }
    
    // TC : O(N^2)
    // SC : O(1)
    ll way_2(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                // points on the x-axis
                ll xLow1  = bottomLeft[i][0];
                ll xLow2  = bottomLeft[j][0];
                ll xHigh1 = topRight[i][0];
                ll xHigh2 = topRight[j][0];
                
                // points on the y-axis 
                ll yLow1  = bottomLeft[i][1];
                ll yLow2  = bottomLeft[j][1];
                ll yHigh1 = topRight[i][1];
                ll yHigh2 = topRight[j][1];
                
                // find intersection of points on the x-axis
                ll xLow   = max(xLow1 , xLow2);
                ll xHigh  = min(xHigh1, xHigh2);
                
                // find intersection of points on the y-axis
                ll yLow   = max(yLow1 , yLow2);
                ll yHigh  = min(yHigh1, yHigh2);
                
                // find x-side length and y-side length
                ll xSide  = max(xHigh - xLow, 0LL);
                ll ySide  = max(yHigh - yLow, 0LL);
                
                // min length of both x, y side
                ll side   = min(xSide, ySide);
                
                maxArea   = max(maxArea, side * side);
            }
        }
        return maxArea;
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        // return way_1(bottomLeft, topRight);
        
        return way_2(bottomLeft, topRight);
    }
};