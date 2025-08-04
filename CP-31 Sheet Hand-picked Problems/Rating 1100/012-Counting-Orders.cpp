// https://codeforces.com/problemset/problem/1827/A




#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1e9 + 7;

ll getTotalWays(vector<ll> &a, vector<ll> &b, int n) {
    sort(begin(a), end(a));
    sort(rbegin(b), rend(b));

    ll ways = 1;
    for (int i = 0; i < n; i ++) {
        int idx = upper_bound(begin(a), end(a), b[i]) - begin(a);
        ll cntGreater = (n - idx - i);
        ways = (ways * cntGreater) % M;
    }
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll &v : a) cin >> v;
        for (ll &v : b) cin >> v;
        cout << getTotalWays(a, b, n) << endl;
    }
    return 0;
}