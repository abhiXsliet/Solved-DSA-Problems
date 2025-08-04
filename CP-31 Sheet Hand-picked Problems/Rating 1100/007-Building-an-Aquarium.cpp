// https://codeforces.com/problemset/problem/1873/E




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getCapactity(vector<ll> &vec, ll mid, ll n, ll x) {
    ll capacity = 0;
    for (ll &val : vec) {
        capacity += (mid - val) <= 0 ? 0 : (mid - val);
    }
    return capacity;
}

ll getOptimalHeight(vector<ll> &v, ll n, ll x) {
    ll low = 1, high = 1e10;
    ll ans = 1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll cap = getCapactity(v, mid, n, x);
        if (cap == x) {
            return mid;
        } else if (cap < x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        for (ll &val : v) cin >> val;
        cout << getOptimalHeight(v, n, x) << endl;
    }
    return 0;
}