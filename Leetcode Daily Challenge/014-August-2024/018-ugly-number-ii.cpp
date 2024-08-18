// https://leetcode.com/problems/ugly-number-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isUgly(int num) {
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }

    // TC : O(NUM * log(N))
    // SC : O(1)
    int brute(int n) {
        int num = 1;

        while (n > 0) {
            if (isUgly(num)) 
                n --;
            if (n > 0) 
                num ++;
        }

        return num;
    }

    // TC : O(N)
    // SC : O(N)
    int optimal_1(int n) {
        // dp[i] represents ith ugly no.
        vector<int> dp(n + 1, 0);

        dp[1] = 1;  // 1st ugly no.

        int i2, i3, i5;
        i2 = i3 = i5 = 1;

        for (int i = 2; i <= n; i ++) {
            int i2_ugly = dp[i2] * 2;
            int i3_ugly = dp[i3] * 3;
            int i5_ugly = dp[i5] * 5;

            int min_ugly = min({i2_ugly, i3_ugly, i5_ugly});

            dp[i] = min_ugly;

            // increment pointer of min_ugly no.
            if (i2_ugly == min_ugly) i2 ++;
            if (i3_ugly == min_ugly) i3 ++;
            if (i5_ugly == min_ugly) i5 ++;
        }

        return dp[n];   // nth ugly no.
    }
public:
    int nthUglyNumber(int n) {
        // return brute(n);

        return optimal_1(n);
    }
};