// https://leetcode.com/problems/power-of-two/




#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    // TC : O(logN)
    bool approach_1(int n) {
        while (n) {
            if (n == 0 || n == 1) return true;
            if (n % 2) return false;
            else n /= 2;
        }
        return false;
    }

    // TC : O(1)
    bool approach_2(int n) {
        long long ans = 1;
        for (int i = 0; i <= 31; i ++) {
            if (ans == n) return true;
            ans *= 2;
        }
        return false;
    }

    // TC : O(1)
    bool approach_3(int n) {
        for (int i = 0; i <= 31; i ++) {
            if (n == pow(2, i)) return true;
        }
        return false;
    }

    // TC : O(1)
    bool approach_4(long n) {
        return (n && !(n & (n - 1)));
    }
public:
    bool isPowerOfTwo(int n) {
        // return approach_1(n);
        // return approach_2(n);
        // return approach_3(n);    
        return approach_4(n);    // optimal
    }
};