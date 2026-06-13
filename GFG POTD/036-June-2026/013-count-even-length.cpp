// https://www.geeksforgeeks.org/problems/count-even-length1907/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int computeValue(int n) {
        vector<long long> fact(2 * n + 1, 1);

        for (int i = 1; i <= 2 * n; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        long long num = fact[2 * n];
        long long den = (fact[n] * fact[n]) % MOD;

        return (num * power(den, MOD - 2)) % MOD;
    }
};