// https://leetcode.com/problems/count-ways-to-build-good-strings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    int M = 1e9 + 7;
    int t[100001];

    int solve(int low, int high, int zero, int one, int len) {
        if (len > high) return 0;

        if (t[len] != -1) return t[len]; 

        return t[len] = (((len >= low && len <= high) ? 1 : 0) + 
                        solve(low, high, zero, one, len + zero) % M + 
                        solve(low, high, zero, one, len + one ) % M) % M;
                     
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(int low, int high, int zero, int one) {
        memset(t, -1, sizeof(t));
        return solve(low, high, zero, one, 0) % M;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        return approach_1(low, high, zero, one);
    }
};