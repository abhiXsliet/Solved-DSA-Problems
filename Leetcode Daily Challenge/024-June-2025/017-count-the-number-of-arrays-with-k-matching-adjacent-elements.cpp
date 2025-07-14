// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/




#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
class Solution {
private:
    using ll = long long;

    ll findPower_recursive(ll a, ll b) {
        if (b == 0) return 1;
        ll half = findPower_recursive(a, b/2);
        ll res  = (half * half) % M;
        if (b % 2) {
            res = (res * a) % M;
        }
        return res;
    }

    ll findPower_iterative(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % M;
            }
            b >>= 1;
            a = (a * a) % M;
        }
        return res;
    }

    ll getNCR(ll n, ll r, vector<ll> &factorial, vector<ll> &invFactorial) {
        ll a = factorial[n];
        ll b = invFactorial[n - r] * invFactorial[r] % M;
        return (a * b) % M;
    }
public:
    // TC : O(N + log(n - k - 1))
    // SC : O(N)
    int countGoodArrays(int n, int m, int k) {
        vector<ll> factorial(n + 1, 1);
        for (int i = 2; i <= n; i ++) {
            factorial[i] = (factorial[i - 1] * i) % M;
        }

        vector<ll> invFactorial(n + 1, 1);
        for (int i = 2; i <= n; i ++) {
            invFactorial[i] = findPower_iterative(factorial[i], M - 2) % M;   // log(M - 2)
        }

        ll result = getNCR(n - 1, k, factorial, invFactorial) % M;
        result    = (result * m) % M;
        result    = (result * findPower_iterative(m - 1, n - k - 1)) % M; // log(n - k - 1)
        return result;
    }
};