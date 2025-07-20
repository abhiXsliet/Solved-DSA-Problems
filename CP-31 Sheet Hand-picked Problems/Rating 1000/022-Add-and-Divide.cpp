// https://codeforces.com/problemset/problem/1485/A




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll minOperations(ll a, ll b) {
    ll minOpr = INT_MAX;
    ll oper = 0;
    for (int i = 0; i <= 31; i ++) {
        ll newB = (b + i);
        oper    = i;
        ll newA = a;
        while (newA) {
            if (newB == 1) break;
            newA = newA / newB;
            oper += 1;
        }
        if (newB > 1) minOpr = min(minOpr, oper);
    }
    return minOpr;
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
        cout << minOperations(a, b) << endl;
    }
    return 0;
}