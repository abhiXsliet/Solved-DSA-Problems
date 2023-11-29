// https://leetcode.com/problems/number-of-1-bits/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(log(N))
    int solve_approach_1(uint32_t n) {
        int ans = 0;
        while(n) {
            if (n & 1) {
                ans ++;
            }
            n = n >> 1;
        }
        return ans;
    }

    // TC = O(log(N))
    int solve_approach_2(uint32_t n) {
        int ans = 0;
        while(n) {
            ans += n % 2;

            n = n >> 1;
        }
        return ans;
    }

    // TC = O(1)
    // ((num >> i) & 1) -> to find the ith bit of a number
    int solve_approach_3(uint32_t n) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if ( (n >> i ) & 1 == 1)
                ans ++;
        }
        return ans;
    }

    // TC = O(K) -> where k = no. of 1-bits
    // n = (n & (n - 1)) -> to unset the rightmost set bit of a number
    int solve_approach_4(uint32_t n) {
        int ans = 0;
        while(n) {
            n = (n & (n - 1));
            ans ++;
        }
        return ans;
    }

    // TC = O(K) -> where k = no. of 1-bits
    int solve_approach_5(uint32_t n) {
        return __builtin_popcount(n);
    }

public:
    int hammingWeight(uint32_t n) {
        // return solve_approach_1(n);

        // return solve_approach_2(n);

        // return solve_approach_3(n);

        // return solve_approach_4(n);

        return solve_approach_5(n);
    }
};