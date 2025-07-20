// https://codeforces.com/problemset/problem/1418/A




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMinOpr(ll x, ll y, ll k) {
    // total sticks req. to craft k torches = k + k*y - 1;
    // trade-1 req. to reach total no. of sticks = ceil(k + k*y - 1 / x - 1)
    // trade-2 req. to reach total no. of coals  = k*y / y = k
    ll a  = ((k + (k*y)) - 1);
    ll b  = (x - 1);

    ll t1 = ((a + b - 1) / (b));

    ll t2 = k;

    return (t1 + t2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        ll x, y, k;
        cin >> x >> y >> k;
        cout << getMinOpr(x, y, k) << endl;
    }
    return 0;
}