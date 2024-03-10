// https://leetcode.com/problems/arranging-coins/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(sqrt(N))
    // SC : O(1)
    int solve_approach_1(int n) {
        int rows = 0;
        for (int i = 1; i <= n; i++) {
            if (n - i >= 0) {
                n -= i;
                rows ++;
            }
        }
        return rows;
    }

    // TC : O(log(N))
    // SC : O(1)
    int solve_approach_2(int n) {
        int ans = 0;
        int lo  = 1, hi = n;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long sum = mid * (mid + 1) / 2;
            if (sum > n) {
                hi = mid - 1;
            }
            else if (sum < n) {
                ans = mid;
                lo  = mid + 1;
            }
            else return mid;
        }
        return ans;
    }
public:
    int arrangeCoins(int n) {
        // return solve_approach_1(n);

        return solve_approach_2(n);
    }
};