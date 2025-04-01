// https://leetcode.com/problems/separate-squares-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double getLowestPt(vector<vector<int>>& squares) {
        double result = (squares[0][1] * 1.0);
        for (vector<int>& square : squares) {
            result = min(result, (square[1] * 1.0));
        }
        return result;
    }

    double getHighestPt(vector<vector<int>>& squares) {
        double result = (squares[0][1] + squares[0][2]) * 1.0;
        for (vector<int>& square : squares) {
            result = max(result, (square[1] + square[2]) * 1.0);
        }
        return result;
    }

    bool isLowerAreaLargerOrEqual(vector<vector<int>>& squares, double mid) {
        double lowerArea = 0.0, upperArea = 0.0;
        for (vector<int>& square : squares) {
            double bottom = square[1], side = square[2], top = bottom + side;
            if (top <= mid) {
                lowerArea += (side * side);
            } else if (bottom > mid) {
                upperArea += (side * side);
            } else {
                double aboveLen = (top - mid), belowLen = (mid - bottom);
                upperArea += (aboveLen * side);
                lowerArea += (belowLen * side); 
            }
        }
        return lowerArea >= upperArea;
    }
public:
    // TC : O(n*log(2e14))
    // SC : O(1)
    double separateSquares(vector<vector<int>>& squares) {
        double precision = 1e-5;
        double low  = getLowestPt(squares);
        double high = getHighestPt(squares);
        double ans  = 0.0;
        while (high - low > precision) {
            double mid = (low + high) / 2;
            if (isLowerAreaLargerOrEqual(squares, mid)) {
                ans  = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        return ans;
    }
};