// https://leetcode.com/problems/set-intersection-size-at-least-two/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        auto lambda = [](auto &vec1, auto &vec2) {
            if (vec1[1] != vec2[1])
                return vec1[1] < vec2[1];
            return vec1[0] > vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        int result = 0;
        int first  = -1;
        int second = -1;

        for (int i = 0; i < n; ++i) {
            int l = intervals[i][0];
            int r = intervals[i][1];


            if (l <= first)
                continue;

            if (l > second) {
                result += 2;
                second = r;
                first = r - 1;
            } else {
                result += 1;
                first = second;
                second = r;
            }
        }
        return result;
    }
};