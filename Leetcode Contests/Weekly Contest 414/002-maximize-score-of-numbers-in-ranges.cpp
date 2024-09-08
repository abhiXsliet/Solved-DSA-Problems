// https://leetcode.com/contest/weekly-contest-414/problems/maximize-score-of-numbers-in-ranges/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    bool isPossible(vector<int>& start, ll x, int d) {
        // Check if it is possible to make a minimum absolute difference of x ?? 
        ll prev = start[0];

        for (int i = 1; i < start.size(); i ++) {
            ll nextVal = max((ll)start[i], prev + x);
            if (nextVal > start[i] + d) 
                return false;
            prev = nextVal;
        }

        return true;
    }
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int maxPossibleScore(vector<int>& start, int d) {
        int n    = start.size();

        sort(begin(start), end(start));

        int low  = 0;
        int high = 2e9;
        int ans  = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (isPossible(start, mid, d)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};