// https://leetcode.com/problems/merge-intervals/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * log(N))
    // SC : O(1) -> no extra space used other than returning the ans
    vector<vector<int>> solve_way_1(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end   = intervals[0][1];

        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= end) {
                //updating end when overlapping occurs
                end = max(intervals[i][1], end);
            }
            else{
                //updating ans when no overlapping occurs
                ans.push_back({start, end});
                //updting start
                start = intervals[i][0];
                //updating end
                end = intervals[i][1];
            }
        }
        //add the last interval to the ans
        ans.push_back({start, end});
        return ans;
    }

    // TC : O(N*log(N))
    // SC : O(1)   
    vector<vector<int>> solve_way_2(vector<vector<int>>& ranges) {     
        vector<vector<int>> result;
        if (ranges.empty()) return result;
        sort(begin(ranges), end(ranges));
        result.push_back(ranges[0]);
        for (int i = 1; i < ranges.size(); i ++) {
            if (result.back()[1] >= ranges[i][0]) {
                if (result.back()[1] < ranges[i][1]) {
                    result.back()[1] = ranges[i][1];
                }
            } else {
                result.push_back(ranges[i]);
            }
        }
        return result;
    }

    // TC = O(N * log(N))
    // SC = O(1) -> no extra space used other than returning the ans
    vector<vector<int>> solve_way_3(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<vector<int>> result;
        for (auto& interval : intervals) {
            
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // return solve_way_1(intervals);
        
        // return solve_way_2(intervals);

        return solve_way_3(intervals);
    }
};