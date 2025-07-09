// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxGapLenInWindowK(vector<int> &gaps, int k) {
        int n = gaps.size();
        int i = 0, j = k, maxGap = gaps[j];
        while (j < n) {
            if (j - i > k) i ++;
            int gap = (gaps[j] - ((i - 1) >= 0 ? gaps[i - 1] : 0));
            maxGap  = max(maxGap, gap);
            j ++;
        }
        return maxGap;
    }
public:
    // TC : O(N)
    // SC : O(N)
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; i ++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);

        // calculate the prefix sum 
        for (int i = 1; i < gaps.size(); i ++) {
            gaps[i] += gaps[i - 1];
        }

        return maxGapLenInWindowK(gaps, k);
    }
};