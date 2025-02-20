// https://leetcode.com/problems/non-overlapping-intervals/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));

        int count = 0;
        int endOfInterval = INT_MIN;
        for (auto& i : intervals) {
            if (i[0] >= endOfInterval) {
                endOfInterval = i[1];
            } else {
                count += 1;
                endOfInterval = min(endOfInterval, i[1]);   // so that more no. of intervals can be non overlapped
            }
        }
        return count;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_2(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto cmp = [&](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        };
        sort(begin(intervals), end(intervals), cmp);

        int count = 0;
        int endOfInterval = INT_MIN;
        for (auto& i : intervals) {
            if (i[0] >= endOfInterval) {
                endOfInterval = i[1];
            } else {
                count += 1;
            }
        }
        return count;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // return approach_1(intervals);
        return approach_2(intervals);
    }
};