// https://leetcode.com/problems/minimum-array-end/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    long long approach_1(int n, int x) {
        long long ans = x;
        for (int i = 1; i < n; i++) {
            ans = (ans + 1) | x;    // get next bigger number
        }
        return ans;
    }

    // TC : O(log(N))
    // SC : O(1)
    // Approach : Split all bits of (n - 1) & fill it into empty bits of x
    long long approach_2(int n, int x) {
        n --;
        long long ans = x;
        for (long long b = 1; n > 0; b <<= 1) {
            if ((b & x) == 0) {
                ans |= (n & 1) * b;
                n  >>= 1;
            }
        }
        return ans;
    }
public:
    long long minEnd(int n, int x) {
        // return approach_1(n, x);

        return approach_2(n, x);
    }
};