// https://leetcode.com/problems/delete-columns-to-make-sorted/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int del = 0;

        for (int col = 0; col < m; col++) {
            for (int row = 1; row < n; row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    del++;       // this column is not sorted
                    break;       // no need to check further rows
                }
            }
        }
        return del;
    }
};