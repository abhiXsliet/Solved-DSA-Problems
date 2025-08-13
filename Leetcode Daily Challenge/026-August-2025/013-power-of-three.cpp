// https://leetcode.com/problems/power-of-three/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log3(n))
    // SC : O(1)
    bool approach_1(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_2(int n) {
        const int MAX_POW3 = 1162261467;    // 3^19 fits in 32-bit integer
        return ((n > 0) && (MAX_POW3 % n == 0));
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_3(int n) {
        if (n < 1) return false;

        double logBase3 = log10(n) / log10(3);

        double rounded  = round(logBase3);

        // Compare with a small epsilon to account for floating-point error
        const double epsilon = 1e-10; 

        return fabs(logBase3 - rounded) < epsilon;
    }

    // TC : O(log3(n))
    // SC : O(1)
    bool approach_4(int n) {
        if (n < 1) return false;

        double logBase3 = log(n) / log(3);
        int exponent    = round(logBase3);

        long ans = 1;
        for (int i = 0; i < exponent; i ++) ans *= 3;

        return ans == n;
    }
public:
    bool isPowerOfThree(int n) {
        // return approach_1(n); 
        // return approach_2(n);  
        // return approach_3(n);   // not recommended  
        return approach_4(n);    
    }
};