// https://leetcode.com/problems/number-of-substrings-with-only-1s/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1e9+7;

    int numSub(string s) {
        int result = 0;
        int count1 = 0;

        for(char ch : s) {
            if (ch == '1') {
                count1++;
                result = (result + count1) % M;
            } else {
                count1 = 0;
            }
        }

        return result;
    }
};