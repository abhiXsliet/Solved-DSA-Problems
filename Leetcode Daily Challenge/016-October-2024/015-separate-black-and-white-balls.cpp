// https://leetcode.com/problems/separate-black-and-white-balls/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long cntSwaps = 0;
        int cntBlackBalls  = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '1') 
                cntBlackBalls ++;
            else 
                cntSwaps += cntBlackBalls;
        }
        return cntSwaps;
    }
};