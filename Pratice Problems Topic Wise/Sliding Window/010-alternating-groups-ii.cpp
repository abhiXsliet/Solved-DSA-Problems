// https://leetcode.com/problems/alternating-groups-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(vector<int>& colors, int k) {
        int n        = colors.size();
        int groups   = 0;
        for (int i = 0; i < n; i ++) {
            colors.push_back(colors[i]);
        }

        for (int i = 0; i < n; i ++) {
            bool alternate = 0;
            for (int j = i + 1; j < i + k; j ++) {
                if (colors[j] != colors[j - 1]) {
                    alternate = 1;
                } else {
                    alternate = 0;
                    break;
                }
            }
            if (alternate) groups ++;
        }
        return groups;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal(vector<int>& colors, int k) {
        int n        = colors.size();
        int groups   = 0;
        for (int i = 0; i < n; i ++) {
            colors.push_back(colors[i]);
        }

        int i = 0, j = i;
        while (i < n) {
            if (j > 0 && colors[j - 1] == colors[j]) {
                i = j;
            }
            if (j - i + 1 == k) {
                groups += 1;
                i ++;
            }
            j ++;
        }
        return groups;
    }
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // return brute(colors, k);

        return optimal(colors, k);
    }
};