// https://codeforces.com/problemset/problem/1859/B




#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<vector<ll>>& arr, ll n) {
    vector<vector<ll>> result(n, vector<ll>(2, 0));
    for (ll i = 0; i < n; i++) {
        sort(begin(arr[i]), end(arr[i]));
        result[i][0] = arr[i][0];
        result[i][1] = arr[i][1];
    }

    ll firstMin = LONG_LONG_MAX, firstMinIdx = -1, secondMin = LONG_LONG_MAX, secondMinIdx = -1;
    for (ll i = 0; i < n; i++) {
        if (result[i][0] < firstMin) {
            firstMin = result[i][0];
            firstMinIdx = i;
        }
        if (result[i][1] < secondMin) {
            secondMin = result[i][1];
            secondMinIdx = i;
        }
    }

    long long sum = 0;
    for (ll i = 0; i < n; i++) {
        if (i != secondMinIdx) {
            sum += result[i][1];
        }
    }
    return sum + result[firstMinIdx][0];
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vector<ll>> v;
        ll x = n;
        while (x --) {
            ll m;
            cin >> m;
            vector<ll> arr(m);
            for (ll i = 0; i < m; i++) {
                cin >> arr[i];
            }
            v.push_back(arr);
        }
        cout << solve(v, n) << endl;
    }
    return 0;
}