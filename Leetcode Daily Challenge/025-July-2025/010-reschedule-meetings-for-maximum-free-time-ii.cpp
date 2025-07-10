// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; i ++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);

        vector<int> prefix = gaps;
        vector<int> suffix = gaps;
        for (int i = 1; i <= n; i ++) {
            prefix[i] = max(prefix[i], prefix[i - 1]);
            suffix[n - i] = max(suffix[n - i], suffix[n - i + 1]);
        }

        int maxFreeTime = 0;

        for (int i = 0; i < n; i ++) {
            int meetTime = (endTime[i] - startTime[i]);

            int freeTimeRearrange = 0;
            if (((i > 0) && prefix[i - 1] >= meetTime) || ((i + 2 <= n) && meetTime <= suffix[i + 2])) {
                freeTimeRearrange = (meetTime + gaps[i] + gaps[i + 1]);
            }

            int freeTimeHover = (gaps[i] + gaps[i + 1]);

            maxFreeTime = max(maxFreeTime, max(freeTimeRearrange, freeTimeHover));
        }

        return maxFreeTime;
    }
};