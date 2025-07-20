// https://codeforces.com/problemset/problem/1725/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMaxWins(vector<ll> &powers, ll n, ll d) {
    sort(rbegin(powers), rend(powers));
    ll i = 0, j = n - 1;
    ll cntWins = 0;
    while (i <= j) {
        ll req = (d / powers[i]) + 1;
        if (d < powers[j]) {
            cntWins += 1;
            j --;
        } else if (d < powers[i]) {
            cntWins += 1;
            i ++;
        } else {
            i ++;
            req --;
            j = (j - req);
            if (i <= j || abs(j - i) == 1) cntWins += 1;
        }
    }
    return cntWins;
}

int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> powers(n);
    for (ll i = 0; i < n; i ++) {
        cin >> powers[i];
    }
    cout << getMaxWins(powers, n, d) << endl;
    return 0;
}