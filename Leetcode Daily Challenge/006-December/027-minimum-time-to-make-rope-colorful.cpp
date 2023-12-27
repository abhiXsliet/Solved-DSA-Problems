// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve_approach_1(string colors, vector<int>& neededTime) {
        int n = colors.length();
        
        int time    = 0;
        int prevMax = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                prevMax = 0;    // catch
            }

            int curr = neededTime[i];
            
            time   += min(prevMax, curr);
            prevMax = max(prevMax, curr);
        }
        return time;
    }
public:
    int minCost(string colors, vector<int>& neededTime) {
        return solve_approach_1(colors, neededTime);
    }
};