// https://leetcode.com/problems/select-k-disjoint-special-substrings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N*log(N))
    // SC : O(1)
    int simpleCountingNonOverlapMaxIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [&](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int maxNonOverlaps = 0;
        int lastOfInterval = -1;
        for (vector<int>& interval : intervals) {
            if (interval[0] > lastOfInterval) {
                lastOfInterval = interval[1];
                maxNonOverlaps += 1;
            }
        }
        return maxNonOverlaps;
    }

    // This function returns the maximum no. of non-overlapping intervals
    int maximumCountOfNonOverlappingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        auto cmp = [&](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        };
        sort(begin(intervals), end(intervals), cmp);

        int count = 0; // it stores the minimum number of intervals that need to be removed to make the intervals non-overlapping.
        int endOfInterval = INT_MIN;
        for (auto& i : intervals) {
            if (i[0] >= endOfInterval) {
                endOfInterval = i[1];
            } else {
                count += 1;
            }
        }
        return n - count;   // total - min intervals that gets removed to make it non-overlapping
    }

    // TC : O(N + R*log(R)) Where N = string.length() & R = Count of ranges (which could be at max 26)
    // SC : O(N) ~= O(26)
    int approach_1(string s, int k) {
        int n = s.length();
        vector<pair<int, int>> occurances(26, {-1, -1});    // stores first and last occurances of each characters
        for (int i = 0; i < n; i ++) {
            int idx = s[i] - 'a';
            if (occurances[idx].first == -1) {
                occurances[idx].first = i;
            }
            occurances[idx].second = i;
        }
        
        vector<vector<int>> ranges;
        for (char ch = 'a'; ch <= 'z'; ch ++) {
            int idx   = ch - 'a';
            int start = occurances[idx].first;
            int end   = occurances[idx].second;
            bool isOk = true;

            if (start == -1) continue;

            // Traversing on interval to maximize the end point of an interval using its inside characters of substring
            for (int j = start + 1; j < end; j ++) {
                end = max(end, occurances[s[j] - 'a'].second);
                if (occurances[s[j] - 'a'].first < start) isOk = false;
            }

            if (isOk && (end - start + 1 != n)) {
                ranges.push_back({start, end});
            }
        }
        int count = maximumCountOfNonOverlappingIntervals(ranges);
        return count >= k;
    }

    // TC : O(N + R*log(R)) Where N = string.length() & R = Count of ranges (which could be at max 26)
    // SC : O(N) ~= O(26)
    bool approach_2(string s, int k) {
        int n = s.length();
        unordered_map<char, int> firstOcc, lastOcc;
        vector<vector<int>> intervals;

        for (int i = 0; i < n; i ++) {
            if (!firstOcc.count(s[i])) firstOcc[s[i]] = i;
            lastOcc[s[i]] = i;
        }

        for (char ch = 'a'; ch <= 'z'; ch ++) {
            if (!firstOcc.count(ch)) continue;

            int  left = firstOcc[ch];
            int right = lastOcc[ch];
            bool isOk = true;

            for (int j = left + 1; j < right; j ++) {
                right = max(right, lastOcc[s[j]]);
                if (firstOcc[s[j]] < left) isOk = false;
            }
            
            if (right - left + 1 != n && isOk) {
                intervals.push_back({left, right});
            }
        }

        // int count = maximumCountOfNonOverlappingIntervals(intervals);
        int count = simpleCountingNonOverlapMaxIntervals(intervals);
        return count >= k;
    }
public:
    bool maxSubstringLength(string s, int k) {
        // return approach_1(s, k); // using vector
        return approach_2(s, k); // Using Map
    }
};