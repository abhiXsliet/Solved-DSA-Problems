// https://codeforces.com/problemset/problem/1850/E




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cardboardArea(vector<ll> &pic, ll w) {
    // C = (si + 2w)^2 => C = (s1 + 2w)^2 + (s2 + 2w)^2 + .... + (sn + 2w)^2

    ll total = 0;
    for (ll &si : pic) {
        ll len = (si + (2*w));
        total += (len * len);
        if (total > 1e18) return total;
    }
    return total;
}

ll getW(vector<ll> &pic, ll c) {
    ll low = 0, high = 1e9;
    ll ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll area = cardboardArea(pic, mid);
        if (area >= c) {
            ans  = mid;
            high = mid - 1;
        } else {
            low  = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, c;
        cin >> n >> c;
        vector<ll> picS(n);
        for (ll &val : picS) cin >> val;
        cout << getW(picS, c) << endl;
    }
    return 0;
}