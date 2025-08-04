// https://codeforces.com/problemset/problem/1869/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMinCost(vector<pair<ll, ll>> &vec, ll n, ll k, pair<ll, ll> &p1, pair<ll, ll>& p2) {
    ll xa = p1.first, ya = p1.second;   // source coordinates
    ll xb = p2.first, yb = p2.second;   // destination coordinates

    ll direct = abs(xa - xb) + abs(ya - yb);

    if (k <= 1) {
        return direct;
    }

    ll mini1 = LLONG_MAX, mini2 = LLONG_MAX;
    for (int i = 0; i < k; i ++) {
        ll x = vec[i].first, y = vec[i].second; // major city coordinates

        mini1 = min(mini1, (abs(xa - x) + abs(ya - y)));
        mini2 = min(mini2, (abs(x - xb) + abs(y - yb)));
    }
    return min(direct, (mini1 + mini2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<ll, ll>> vec(n);
        pair<ll, ll> p1 = {-1, -1};
        pair<ll, ll> p2 = {-1, -1};
        int cnt = 1;
        for (auto&p : vec) {
            cin >> p.first >> p.second;
            if (cnt == a) {
                p1 = p;
            }
            if (cnt == b) {
                p2 = p;
            }
            cnt += 1;
        }
        
        cout << getMinCost(vec, n, k, p1, p2) << endl;
    }
    return 0;
}