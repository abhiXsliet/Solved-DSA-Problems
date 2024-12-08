// https://leetcode.com/problems/two-best-non-overlapping-events/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int dp[100001][3];

    int binarySearch(vector<vector<int>>& events, int endTime) {
        int low = 0, high = n - 1;
        int res = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > endTime) {
                res  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return res;
    }

    // TC : O(N*log(N)) Visiting each states once only
    // SC : O(N)
    int solve(vector<vector<int>>& events, int i, int count) {
        if (count == 2 || i >= n) return 0;

        if (dp[i][count] != -1) return dp[i][count];

        int nextValidEventIdx = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidEventIdx, count + 1);
        int skip = solve(events, i + 1, count);

        return dp[i][count] = max(take, skip);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        int count = 0;
        sort(begin(events), end(events));
        memset(dp, -1, sizeof(dp));
        return solve(events, 0, count);
    }
};