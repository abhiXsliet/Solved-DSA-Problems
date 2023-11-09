// https://leetcode.com/problems/count-number-of-homogenous-substrings/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;
    
    // TC = O(N)
    // SC = O(1)
    int solve_approach_1(string s) {
        int result = 0;
        int length = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                length++;
            }
            else {
                length = 1;
            }
            result = (result + length) % MOD;
        }
        return result;
    }

public:
    int countHomogenous(string s) {
        return solve_approach_1(s);
    }
};