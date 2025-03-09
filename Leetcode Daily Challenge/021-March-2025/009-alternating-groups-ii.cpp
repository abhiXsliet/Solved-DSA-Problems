// https://leetcode.com/problems/alternating-groups-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int i = 0, j = 0;
        int alternatingGroups = 0;
        int next = colors[0];
        while (i < n) {
            if (next != colors[j % n]) {
                next = 1 - (colors[j % n]);
                i = j;
            } else {
                next = 1 - colors[j % n];
            }

            if (j - i + 1 == k) {
                alternatingGroups += 1;
                i ++;
            }
            
            j ++;
        }
        return alternatingGroups;
    }
};