// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    // TC : O(N)
    // SC : O(N)
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        unordered_map<int, vector<int>> mpp;    // stores the conflictingPoints for each number (a, b) where a <= b
        
        for (vector<int> &cp : conflictingPairs) {
            if (cp[0] > cp[1]) swap(cp[0], cp[1]);
            mpp[cp[1]].push_back(cp[0]);
        }

        // extra[i] = number of extra subarray on removal of conflicting pair i
        vector<ll> extraPoints(n + 1, 0); 

        ll totalValidSubarrays = 0, firstMaxConfict = 0, secondMaxConflict = 0;

        for (int i = 1; i <= n; i ++) { // subarray ending at i
            
            for (int &val : mpp[i]) {
                if (val >= firstMaxConfict) {
                    secondMaxConflict = firstMaxConfict;
                    firstMaxConfict   = val;
                } else if (val > secondMaxConflict) {
                    secondMaxConflict = val;
                }
            }

            totalValidSubarrays += (i - firstMaxConfict);

            extraPoints[firstMaxConfict] += (firstMaxConfict - secondMaxConflict);
        }

        return (totalValidSubarrays + *max_element(begin(extraPoints), end(extraPoints)));
    }
};