// https://leetcode.com/problems/power-of-four/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(log(base-4)(N))
    // SC = O(1)
    bool solve_brute(int n) {
        if (n == 0) return 0;
        for(long i = 1; i <= n; i*=4) {
            if (i == n) {
                return true;
            }
        }
        return false;
    }

    // TC = O(log(base-4)(N))
    // SC = O(1)
    bool solve_better(int n) {
        if (n == 0) return 0;

        while(n % 4 == 0) {
            n /= 4;
        }

        if (n == 1) return 1;
        else return 0;
    }

    // TC = O(1)
    // SC = O(1)
    bool solve_optimal_1(int n) {
        if (n <= 0) return 0;

        int x = (log(n) / log(4));

        if (pow(4, x) == n) 
            return true;
        else return false;
    }

    // TC = O(1)
    // SC = O(1)
    bool solve_optimal_2(int n) {
        if (n <= 0)
            return false;

        if ((n & (n-1)) == 0 && (n-1) % 3 == 0)
            return true;
        return false;
    }
public:
    bool isPowerOfFour(int n) {
        // return solve_brute(n);

        // return solve_better(n);

        // return solve_optimal_1(n);

        return solve_optimal_2(n);
    }
};