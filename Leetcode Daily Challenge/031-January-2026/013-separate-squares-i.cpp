// https://leetcode.com/problems/separate-squares-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    double getMin(vector<vector<int>>& squares) {
        double mini = squares[0][0];
        for (vector<int> &sq : squares) {
            mini = min(mini, sq[0]*1.0);
        }
        return mini;
    }

    double getMax(vector<vector<int>>& squares) {
        double maxi = squares[0][1] + squares[0][2];
        for (vector<int> &sq : squares) {
            maxi = max(maxi, sq[1]*1.0 + sq[2]*1.0);
        }
        return maxi;
    }

    double isLowerAreaGreater(vector<vector<int>>& squares, double mid) {
        double lowerArea = 0.0, upperArea = 0.0;
        for (vector<int> &sq : squares) {
            double bottomY = sq[1];
            double side = sq[2];
            double topY = bottomY + side;

            if (topY <= mid) {  // whole sq. lies in the lower part of 'mid' horizontal line
                lowerArea += (side * side);
            } else if (bottomY >= mid) {    // whole sq. lies in upper part of 'mid' horizontal line
                upperArea += (side * side);
            } else {    // sq. lies somewhere in the middle of line
                double belowPart = mid - bottomY;
                double abovePart = topY - mid;
                lowerArea += (belowPart * side);
                upperArea += (abovePart * side);
            }
        }
        return lowerArea >= upperArea;
    }
public:
    // TC : O(n * log(10^14)) where n = size of squares
    // SC : O(1)
    double separateSquares(vector<vector<int>>& squares) {
        double low  = getMin(squares);
        double high = getMax(squares);
        double prec = 1e-5;

        while (high - low > prec) {
            double mid = low + (high - low) / 2;
            if (isLowerAreaGreater(squares, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        } 

        return low;
    }
};