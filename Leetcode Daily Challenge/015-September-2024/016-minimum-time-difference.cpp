// https://leetcode.com/problems/minimum-time-difference/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(N)
    int approach_1(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        for (int i = 0; i < n; i ++) {
            string time = timePoints[i];

            string hour = time.substr(0, 2);
            string minu = time.substr(3, 2);

            int hourInt = stoi(hour);
            int minuInt = stoi(minu);

            minutes[i] = hourInt * 60 + minuInt;
        }

        sort(begin(minutes), end(minutes));

        int result = INT_MAX;
        for (int i = 1; i < n; i ++) {
            result = min(result, minutes[i] - minutes[i - 1]);
        }
        return min(result, (24*60) - minutes[n - 1] + minutes[0]);  // catch
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        return approach_1(timePoints);

        // Pending by BUCKET SORT : since the size is limited
        // minimum "00:00" & "23:59" which is 0 & 1439
    }
};