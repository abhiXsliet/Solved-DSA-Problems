// https://leetcode.com/problems/count-days-without-meetings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<vector<int>> mergeIntervals(vector<vector<int>> &meetings) {
        sort(begin(meetings), end(meetings));
        vector<vector<int>> result;
        for (auto &meeting : meetings) {
            if (result.empty() || result.back()[1] < meeting[0]) {
                result.push_back(meeting);
            } else {
                result.back()[1] = max(result.back()[1], meeting[1]);
            }
        }
        return result;
    }
public:
    // TC : O(N*log(N))
    // SC : O(N)
    int countDays(int days, vector<vector<int>>& meetings) {
        meetings = mergeIntervals(meetings);
        
        int initial = meetings[0][0];
        int ans = initial - 1;

        initial = meetings[0][1];
        for (int i = 1; i < meetings.size(); i ++) {
            int l = meetings[i][0];
            int r = meetings[i][1];
            if (l - initial > 1) {
                ans += (l - initial - 1);
            }
            initial = r;
        }
        ans += (days - initial);
        return ans;
    }
};