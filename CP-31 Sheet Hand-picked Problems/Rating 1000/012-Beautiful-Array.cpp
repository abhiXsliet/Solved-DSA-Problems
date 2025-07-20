// https://codeforces.com/problemset/problem/1715/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> getArr(ll n, ll k, ll b, ll s) {
    ll minRange = (k * b);
    ll maxRange = (k * b) + (n * (k - 1));
    if (s < minRange || s > maxRange) return {-1};

    vector<ll> result(n, 0);
    result[0] = (k * b);

    s -= (k * b);

    for (int i = 0; i < n && s > 0; i ++) {
        ll mini = min(s, (k - 1));
        result[i] += mini;
        s -= mini;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);  // disables C and C++ stream sync
    cin.tie(NULL);                // unties cin from cout
    cout.tie(NULL);               // optional, unties cout from flush behavior

    int t;
    cin >> t;
    while (t--) {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        vector<ll> ans = getArr(n, k, b, s);
        for (ll &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}