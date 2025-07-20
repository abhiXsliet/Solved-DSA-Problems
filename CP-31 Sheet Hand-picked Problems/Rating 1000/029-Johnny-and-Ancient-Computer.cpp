// https://codeforces.com/problemset/problem/1362/A




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> getVal(ll x) {
    int power = 0;
    while (x % 2 == 0) {
        x /= 2;
        power += 1;
    }
    return {x, power};
}

ll minOpr(ll a, ll b) {
    // a can be expressed as ra * 2^x
    // b can be expressed as rb * 2^x

    pair<int, int> p1 = getVal(a);
    pair<int, int> p2 = getVal(b);

    int ra = p1.first, rb = p2.first;
    int aPow = p1.second, bPow = p2.second;

    if (ra != rb) { // a can't be made equal to b
        return -1;
    }

    return ceil(abs(aPow - bPow) / 3.0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        ll a, b;
        cin >> a >> b;
        cout << minOpr(a, b) << endl;
    }
    return 0;
}