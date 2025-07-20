// https://codeforces.com/problemset/problem/1704/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMinChange(vector<ll> &piles, ll n, ll x) {
    ll countIncrement = 0;
    ll l1 = piles[0] - x;
    ll r1 = piles[0] + x;
    for (int i = 0; i < n; i ++) {
        ll l2 = piles[i] - x;
        ll r2 = piles[i] + x; 

        ll l = max(l1, l2);
        ll r = min(r1, r2);

        if (l > r) { // no intersection, so add +1 to answer
            countIncrement += 1;
            l1 = l2;
            r1 = r2;
        } else {    // took out the intersection
            l1 = max(l1, l2);
            r1 = min(r1, r2);
        }
    }
    return countIncrement;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        ll n, x;
        cin >> n >> x;
        vector<ll> piles(n);
        for (ll &val : piles) {
            cin >> val;
        }
        cout << getMinChange(piles, n, x) << endl;
    }
    return 0;
}