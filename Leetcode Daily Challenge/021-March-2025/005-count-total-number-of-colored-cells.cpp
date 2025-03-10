// https://leetcode.com/problems/count-total-number-of-colored-cells/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N)
    // SC : O(1)
    ll approach_1(int n) {
        ll base   = 1;
        ll extra  = 0;
        ll result = 0;
        while (n --) {
            result = base + extra;
            base   = result;
            extra += 4;
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N) Recursive Stack Space   
    ll approach_2(int n, int base) {
        if (n == 1) return 1;

        return base + approach_2(n - 1, base - 4);
    }

    // TC : O(1)
    // SC : O(1)   
    ll approach_3(int n) {
        // sum of (n - 1) natural nos. => ((n - 1) * n) / 2
        // formula : 1 + (4 * sum) = 1 + (2 * (n - 1) * n)

        return 1LL + (2LL * (n - 1) * n);
    }
public:
    long long coloredCells(int n) {
        // return approach_1(n);              // Iterative
        // return approach_2(n, 4*(n - 1));   // Recursive
        return approach_3(n);              // Formula
    }
};