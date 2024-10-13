// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int approach_1(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));

        vector<int> endingPoints;
        for (vector<int>& interval : intervals) {
            int startPt  = interval[0];
            int endingPt = interval[1];

            bool flag = 1;
            for (int i = 0; i < endingPoints.size(); i ++) {
                if (startPt > endingPoints[i]) {
                    endingPoints[i] = max(endingPoints[i], endingPt);
                    flag = 0;
                    break;
                } 
            }
            if (flag) {
                endingPoints.push_back(endingPt);
            }
        }
        return endingPoints.size();
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int approach_2(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));

        priority_queue<int, vector<int>, greater<int>> pq;

        for (vector<int>& interval : intervals) {
            int startPt  = interval[0];
            int endingPt = interval[1];

            if (!pq.empty() && startPt > pq.top()) {
                pq.pop();
            }
            pq.push(endingPt);
        }

        return pq.size();
    }
public:
    int minGroups(vector<vector<int>>& intervals) {
        // return approach_1(intervals);   // BRUTE

        return approach_2(intervals);   // OPTIMAL

        // explore LINE SWEEP ALGO?
    }
};