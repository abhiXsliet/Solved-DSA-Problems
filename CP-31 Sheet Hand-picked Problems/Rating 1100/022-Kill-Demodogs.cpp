// https://codeforces.com/problemset/problem/1731/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 + 7;

ll binaryExpo(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) {
            res = (res * a) % M;
        }
        b >>= 1;
        a = (a * a) % M;
    }
    return res;
}

ll squareNaturalSum(ll n) {
    // 1^2 + 2^2 + ... + n^2 => n(n + 1)(2n + 1) / 6

    ll val = ((((n * (n + 1)) % M * (2 * n + 1)) % M ) * (binaryExpo(6, M - 2) % M)) % M;
    return val;
}

ll sumNatural(ll n) {
    // 1 + 2 + 3 + ... + n => n*(n + 1) / 2

    ll val = ((n * (n + 1)) % M * (binaryExpo(2, M - 2) % M)) % M;
    return val;
}

ll getMaxSum(ll n) {
    // (Σ i^2 where i = 1 to n) + (Σ i(i + 1) where i = 1 to n - 1)

    return (2022 * (squareNaturalSum(n) + squareNaturalSum(n - 1) + sumNatural(n - 1))) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        ll n;
        cin >> n;
        cout << getMaxSum(n) << endl;
    }
    return 0;
}