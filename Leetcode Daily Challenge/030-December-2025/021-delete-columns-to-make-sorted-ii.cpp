// https://leetcode.com/problems/delete-columns-to-make-sorted-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M * N)
    // SC : O(1)
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<bool> alreadySorted(m, false);

        int del = 0;
        
        for (int c = 0; c < m; c ++) {

            bool deleted = false;

            for (int r = 0; r < n - 1; r ++) {

                if (!alreadySorted[r] && strs[r][c] > strs[r + 1][c]) {
                    deleted = true;
                    del += 1;
                    break;
                }
            }

            if (deleted) {
                continue;
            }

            for (int r = 0; r < n - 1; r ++) {
                alreadySorted[r] = alreadySorted[r] | (strs[r][c] < strs[r + 1][c]);
            }
        }
        
        return del;
    }
};