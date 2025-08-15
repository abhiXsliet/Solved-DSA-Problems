// https://leetcode.com/problems/power-of-four/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log(N))
    // SC : O(1)
    bool approach_1(int n) {
        if (n < 1) return 0;

        while (n % 4 == 0) n /= 4;

        return n == 1;
    }

    // TC : O(log(N))
    // SC : O(1)
    bool approach_2(int n) {
        if (n < 1) return false;

        double logBase4 = log(n) / log(4);
        int exponent    = round(logBase4);

        long ans = 1;
        for (int i = 0; i < exponent; i ++) ans *= 4;

        return ans == n;
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_3(int n) {
        return (n > 0 && (n & (n - 1)) == 0 && ((n - 1) % 3) == 0);
    }
public:
    bool isPowerOfFour(int n) {
        // return approach_1(n);
        // return approach_2(n);
        return approach_3(n);
    }
};