// https://leetcode.com/problems/count-number-of-trapezoids-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9+7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp; //y -> count

        for(auto &point : points) {
            int y = point[1];
            mp[y]++;
        }

        long long result = 0; //countof trapezoids

        long long prevHorizontalLines = 0;

        for(auto &it : mp) {
            int count = it.second;

            long long horizontalLines = (long long)count * (count-1)/2; //countC2

            result += horizontalLines * prevHorizontalLines;

            prevHorizontalLines += horizontalLines;
        }

        return result % M;


    }
};
