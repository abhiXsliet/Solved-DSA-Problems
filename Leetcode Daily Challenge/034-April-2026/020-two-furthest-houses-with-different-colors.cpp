// https://leetcode.com/problems/two-furthest-houses-with-different-colors/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC : O(2*n)
    int approach_1(vector<int> &colors) {
        int n = colors.size();

        int i = 0, j = n - 1;
        while (i < j && colors[i] == colors[j]) i ++;
        int result = j - i;

        i = 0, j = n - 1;
        while (i < j && colors[i] == colors[j]) j --;
        result = max(result, j - i);

        return result;
    }

    // TC : O(n)
    int approach_2(vector<int> &colors) {
        int n = colors.size();

        int result = 0;
        for (int i = 0; i < n; i ++) {
            if (colors[i] != colors[0]) 
                result = max(result, i);
            if (colors[i] != colors[n - 1])
                result = max(result, abs(i - (n - 1)));
        }
        return result;
    }
public:
    int maxDistance(vector<int>& colors) {
        // return approach_1(colors);
        return approach_2(colors);
    }
};