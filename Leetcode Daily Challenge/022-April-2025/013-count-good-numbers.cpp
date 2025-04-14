// https://leetcode.com/problems/count-good-numbers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int M = 1e9 + 7;
    typedef long long ll;

    ll powerMod(ll a, ll b) {
        ll result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % M;
            }
            a = (a * a) % M;
            b >>= 1;
        }
        return result;
    }

    ll powerRec(ll a, ll b) {
        if (b == 0) return 1;

        ll half = powerRec(a, b/2) % M;
        ll res  = (half * half) % M;
        if (b % 2) res = (res * a) % M;
        return res;
    }

    // TC : O(log(N))
    // SC : O(1)
    int approach_1(ll n) {
        ll evenPart = (n + 1) / 2;
        ll oddPart  = (n / 2);

        // ll part1 = powerMod(5, evenPart) % M;
        // ll part2 = powerMod(4, oddPart) % M;
        
        ll part1 = powerRec(5, evenPart) % M;
        ll part2 = powerRec(4, oddPart) % M;
        
        return (part1 * part2) % M;
    }
public:
    int countGoodNumbers(long long n) {
        return approach_1(n);
    }
};