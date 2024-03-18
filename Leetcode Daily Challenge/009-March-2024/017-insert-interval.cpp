// https://leetcode.com/problems/insert-interval/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) where N = size of intervals
    // SC : O(1) extra space
    vector<vector<int>> approach_1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int index = 0;

        //step 1 : insert all intervals that comes before newInterval
        while(index < n && intervals[index][1] < newInterval[0]) {
            ans.push_back(intervals[index]);
            index++;
        }

        //step 2 : merging overlapping intervals with newInterval
        while(index < n && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        ans.push_back(newInterval);

        //step 3 : Insert all remaining intervals
        while(index < n) {
            ans.push_back(intervals[index]);
            index++;
        }
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return approach_1(intervals, newInterval);
    }
};