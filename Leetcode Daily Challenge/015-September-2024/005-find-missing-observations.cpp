// https://leetcode.com/problems/find-missing-observations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // TC : O(N + M)
    // SC : O(1)
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumRolls  = accumulate(begin(rolls), end(rolls), 0);
        int sumReqrd  = (m + n) * mean;
        int sumRemain = sumReqrd - sumRolls;

        int eachEl = sumRemain / n; // each element should be at least equal to eachEl
        int extra  = sumRemain % n;

        if (eachEl > 6 || eachEl <= 0) 
            return {};

        vector<int> res(n, eachEl);

        int idx = 0;
        while (extra && idx < n) {  // distributing extra left evenly to all
            res[idx] += 1;
            if (res[idx] > 6) 
                return {};
            idx ++;
            extra --;
        }

        return res;
    }
};