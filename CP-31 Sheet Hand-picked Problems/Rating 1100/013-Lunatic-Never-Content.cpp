// https://codeforces.com/problemset/problem/1826/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
} 

ll getHighestX(vector<ll> &vec, int n) {
    ll ans = abs(vec[0] - vec[n - 1]);
    for (int i = 1; i < n; i ++) {
        ans = gcd(ans, abs(vec[i] - vec[n - i - 1]));
    }
    return ans;
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
        cout << getHighestX(vec, n) << endl;
    }
    return 0;
}