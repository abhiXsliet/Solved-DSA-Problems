// https://codeforces.com/problemset/problem/1791/E




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMaxSum(vector<ll> &vec, int n) {
    int cntNeg = 0;
    ll mini = LONG_MAX, total = 0;
    for (ll &val : vec) {
        if (val < 0) cntNeg += 1;
        mini = min(mini, abs(val));
        total += abs(val);
    }
    if (cntNeg % 2) total -= 2*mini;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<ll> vec(n);
        for (ll &val : vec) cin >> val;
        cout << getMaxSum(vec, n) << endl;
    }
    return 0;
}