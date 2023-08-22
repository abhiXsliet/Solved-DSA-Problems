// https://leetcode.com/problems/excel-sheet-column-number/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(int i = 0; i < columnTitle.length(); i++) {
            res *= 26;
            res += columnTitle[i] - 'A' + 1;
        }
        return res;
    }
};