// https://codeforces.com/problemset/problem/1708/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getCeil(int a, int b) {
    return (a + b - 1) / b;
}

pair<bool, vector<ll>> getSolution(ll n, ll l, ll r) {
    vector<ll> ans;
    for (int i = 1; i <= n; i ++) {
        ll val = (getCeil(l, i) * i);
        if (val >= l && val <= r) {
            ans.push_back(val);
        } else {
            return {0, {}};
        }
    }
    return {1, ans};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, l, r;
        cin >> n >> l >> r;

        pair<bool, vector<ll>> ans = getSolution(n, l, r);
        
        if (!ans.first) {
            cout << "No";
        } else {
            cout << "Yes" << "\n";
            for (ll &val : ans.second) cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}