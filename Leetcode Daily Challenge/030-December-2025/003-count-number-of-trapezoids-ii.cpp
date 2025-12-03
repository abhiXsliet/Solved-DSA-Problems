// https://leetcode.com/problems/count-number-of-trapezoids-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        //slope -> {intercepts}
        unordered_map<float, vector<float>> slopeIntercpts;

        unordered_map<int, vector<float>> midPointMap;

        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2-x1;
                int dy = y2-y1;

                float slope, intercept;
                if(x2 == x1) { //dx == 0
                    slope     = 1e9+7; //10000007
                    intercept = x1;
                } else {
                    slope = (float)(y2-y1)/(x2-x1);
                    intercept = (float) (y1*dx - x1*dy) / dx;
                }

                int midPointKey = (x1+x2)*10000 + (y1+y2);

                slopeIntercpts[slope].push_back(intercept);
                midPointMap[midPointKey].push_back(slope);
            }
        }

        for(auto &it : slopeIntercpts) {
            if(it.second.size() <= 1)
                continue;

            map<float, int> mp; //intercept -> count
            for(float intercept : it.second) {
                mp[intercept]++;
            }

            int prevHorizLines = 0;
            for(auto &it : mp) {
                int count = it.second;
                result += count * prevHorizLines; //counting duplicates also

                prevHorizLines += count;
            }
        }

        for(auto &it : midPointMap) {
            if(it.second.size() <= 1)
                continue;
                
            map<float, int> mp;
            for(float slope : it.second) {
                mp[slope]++;
            }

            int prevHorizLines = 0;
            for(auto &it : mp) {
                int count = it.second;
                result -= count * prevHorizLines; //removing duplicates

                prevHorizLines += count;
            }
        }

        return result;
    }
};