// https://leetcode.com/problems/three-consecutive-odds/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool brute(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i + 2 < n; i ++) {
            if ((arr[i] & 1) && (arr[i + 1] & 1) && (arr[i + 2] & 1))
                return true;
        }
        return false;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = 0;
        while (i < n - 2) {
            if (arr[j] % 2 == 0) {
                i = j + 1;
            }
            if (j - i + 1 == 3) {
                return true;
            }
            j = (i >= j) ? i + 1 : j + 1;
        }
        return false;
    }
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        return brute(arr);
        // return optimal(arr);
    }
};