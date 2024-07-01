// https://leetcode.com/problems/three-consecutive-odds/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool approach_1(vector<int>& arr, int n) {
        for (int i = 0; i + 2 < n; i ++) {
            if ((arr[i] & 1) && (arr[i + 1] & 1) && (arr[i + 2] & 1)) 
                return 1;
        }
        return 0;
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_2(vector<int>& arr, int n) {
        int j = 0, window = 0;
        while (j < n) {
            if (arr[j] & 1) window ++;
            else window = 0;

            if (window == 3) return 1;
            j ++;
        }
        return 0;
    }
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        // return approach_1(arr, arr.size()); // LINEAR SEARCH

        return approach_2(arr, arr.size()); // SLIDING WINDOW
    }
};