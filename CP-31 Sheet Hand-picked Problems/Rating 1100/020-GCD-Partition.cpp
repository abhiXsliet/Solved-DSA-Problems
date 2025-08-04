// https://codeforces.com/problemset/problem/1780/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}

ll getMaxGcdPartition(vector<ll> &vec, int n) {
    for (int i = 1; i < n; i ++) vec[i] += vec[i - 1];
    ll maxGcd = 0;
    for (int i = 0; i < n - 1; i ++) {
        ll a = vec[i];
        ll b = vec[n - 1] - vec[i];
        maxGcd = max(maxGcd, gcd(a, b));
    }
    return maxGcd;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n; 
        vector<ll> vec(n);
        for (ll &val : vec) cin >> val;
        cout << getMaxGcdPartition(vec, n) << endl;
    }
    return 0;
}