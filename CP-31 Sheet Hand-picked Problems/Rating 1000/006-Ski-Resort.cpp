// https://codeforces.com/problemset/problem/1840/C




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getTotalDaysCnt(vector<int>& tempr, int n, int k, int q) {
    ll ans = 0;
    int cntDaysNum  = 0, value = 1;
    for (int i = 0; i < n; i ++) {
        if (tempr[i] > q) {
            cntDaysNum = 0;
            value = 1;
        } else {
            cntDaysNum += 1;
            if (cntDaysNum >= k) {
                ans += (value);
                value += 1;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        ll n, k, q;
        cin >> n >> k >> q;
        vector<int> tempr(n);
        for (int i = 0; i < n; i ++) {
            cin >> tempr[i];
        }
        cout << getTotalDaysCnt(tempr, n, k, q) << endl;
    }
    return 0;
}