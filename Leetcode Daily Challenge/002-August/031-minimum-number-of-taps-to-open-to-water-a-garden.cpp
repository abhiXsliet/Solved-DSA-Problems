// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    int solve_greedy(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1, 0);

        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);

            startEnd[start] = max(startEnd[start], end);
        }

        int taps    = 0;
        int maxEnd  = 0;
        int currEnd = 0;

        for (int i = 0; i <= n; i++) {
            if (i > maxEnd) 
                return -1;

            if (i > currEnd) {
                taps++;
                currEnd = maxEnd;
            }

            maxEnd = max(maxEnd, startEnd[i]);
        }

        return taps;
    }

    // TC = O(N^2)
    // SC = O(N^2)
    int solve_mem(int idx, int maxEnd, int gardenLastPoint,
        vector<pair<int, int>>& range, map<pair<int, int>, int>& mpp) {
        // base case
        if (idx >= range.size()) {
            if (maxEnd >= gardenLastPoint) 
                return 0;
            else 
                return 1e9;
        }

        // check in map if the value is stored
        if (mpp.find({idx, maxEnd}) != mpp.end())
            return mpp[{idx, maxEnd}];

        // middle area not possible to water
        if (range[idx].first > maxEnd) 
            return 1e9;
        
        int not_tap_open = solve_mem(idx+1, maxEnd, gardenLastPoint, range, mpp);
        int open_tap = 1 + solve_mem(idx+1, max(maxEnd, range[idx].second),
                             gardenLastPoint, range, mpp);

        return mpp[{idx, maxEnd}] = min(not_tap_open, open_tap);
    }

public:
    int minTaps(int n, vector<int>& ranges) {
        // // Approach - 1 : Greedy
        // return solve_greedy(n, ranges);


        // Approach - 2 : Recursion + Memoization
        vector<pair<int, int>> range;
        map<pair<int, int>, int> mpp;

        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);

            range.push_back({start, end});
        }
        
        sort(range.begin(), range.end());

        int result = solve_mem(0, 0, n, range, mpp);

        return result == 1e9 ? -1 : result;
    }
};