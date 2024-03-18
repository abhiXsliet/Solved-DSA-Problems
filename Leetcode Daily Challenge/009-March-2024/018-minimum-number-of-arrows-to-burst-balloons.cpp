// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:   
    // TC : O(N)
    // SC : O(1)
    bool isPossibleToBurst(vector<vector<int>>& points, int arrows) {
        int endPoint = points[0][1];
        arrows      -= 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > endPoint) {
                arrows --;
                endPoint = points[i][1];
            }
            else {
                endPoint = min(endPoint, points[i][1]);
            }
        }
        return arrows >= 0;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_approach_1(vector<vector<int>>& points) {
        sort(begin(points), end(points));

        int prevSt = points[0][0];
        int prevEn = points[0][1];
        int arrows = 1;

        for (int i = 1; i < points.size(); i++) {
            int currSt = points[i][0];
            int currEn = points[i][1];
            
            if (currSt > prevEn){ // no overlap
                prevEn = currEn;
                arrows ++;
            }
            else {  // overlapping
                prevSt = max(currSt, prevSt);
                prevEn = min(prevEn, currEn);
            }
        }
        return arrows;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_approach_2(vector<vector<int>>& points) {
        int n    = points.size();
        int low  = 0;
        int high = n;
        int ans  = 0;
        
        sort(begin(points), end(points));
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // arrows
            if (isPossibleToBurst(points, mid)) {
                ans  = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // return solve_approach_1(points); 

        return solve_approach_2(points);    // BS ON ANSWER
    }
};