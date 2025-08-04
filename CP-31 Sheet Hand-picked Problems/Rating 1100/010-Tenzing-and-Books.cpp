// https://codeforces.com/problemset/problem/1842/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isSameBits(ll val, ll x) {
    for (int i = 0; i <= 31; i ++) {
        bool bit1 = ((1 << i) & val);
        bool bit2 = ((1 << i) & x);
        if (bit2 == 1) continue;
        if (bit1 == 1) return false;
    }
    return true;
}

bool isPossibleToObtainX(ll n, ll x, vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    ll val = 0;
    bool canUse1 = 1, canUse2 = 1, canUse3 = 1;
    for (ll i = 0; i < n; i ++) {
        if (isSameBits(a[i], x) && canUse1) { 
            val |= a[i];
        } else canUse1 = 0;
        
        if (isSameBits(b[i], x) && canUse2) {
            val |= b[i];
        } else canUse2 = 0;

        if (isSameBits(c[i], x) && canUse3) {
            val |= c[i];
        } else canUse3 = 0;
    }
    return val == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n), b(n), c(n);
        for (ll &v : a) cin >> v;
        for (ll &v : b) cin >> v;
        for (ll &v : c) cin >> v;
        if (isPossibleToObtainX(n, x, a, b, c))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}