// https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N * log(N))
    // SC : O(N)
    vector<vector<int>> approach_1(vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        
        sort(begin(intervals), end(intervals));
        
        vector<vector<int>> result;
        for (vector<int> &interval : intervals) {
            if (result.empty() || interval[0] > result.back()[1]) {
                result.push_back(interval);
            } else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<vector<int>> approach_2(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;
        
        // Step-1 : Left Part : Intervals which ends before newInterval start
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i ++;
        }
        
        // Step-2 : Merge Part : Overlapping Interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i ++;
        }
        result.push_back(newInterval);
        
        // Step-3 : Right Part : Intervals which start after newintervals end
        while (i < n) {
            result.push_back(intervals[i]);
            i ++;
        }
        
        return result;
    }
    
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        // return approach_1(intervals, newInterval);
        return approach_2(intervals, newInterval);
    }
};