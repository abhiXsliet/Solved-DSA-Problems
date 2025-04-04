// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(1, startTime[0]);
        for (int i = 1; i < n; i ++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);

        int gSize = gaps.size();
        vector<int> prefix(gSize, 0);   // largest freeslots to the left
        vector<int> suffix(gSize, 0);   // largest freeslots to the right

        for (int i = 2; i < gSize; i ++) {
            prefix[i] = max(prefix[i - 1], gaps[i - 2]);
        }
        for (int i = gSize - 2; i >= 0; i --) {
            suffix[i] = max(suffix[i + 1], gaps[i + 1]);
        }

        int maxFreeTime = 0;
        for (int i = 1; i < gSize; i ++) {
            int duration = endTime[i - 1] - startTime[i - 1];
            if (duration <= max(prefix[i], suffix[i])) {
                maxFreeTime = max(maxFreeTime, gaps[i - 1] + duration + gaps[i]);
            }
            // slide the meeting without rescheduling
            maxFreeTime = max(maxFreeTime, gaps[i - 1] + gaps[i]);
        }
        return maxFreeTime;
    }
};