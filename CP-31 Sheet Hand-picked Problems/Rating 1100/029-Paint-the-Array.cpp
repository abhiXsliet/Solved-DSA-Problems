// https://codeforces.com/problemset/problem/1618/C




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isGoodGcd(ll val, vector<ll> &arr, int n) {
    if (val == 1) return false;

    for (int i = 1; i < n; i ++) {
        if ((arr[i] % val == 0) && (arr[i - 1] % val == 0))
            return false;
    }
    return true;
}

ll paintArray(vector<ll> &arr, int n) {
    ll gcd_1 = arr[0];
    for (int i = 2; i < n; i += 2) {
        gcd_1 = __gcd(gcd_1, arr[i]);
    }

    if (isGoodGcd(gcd_1, arr, n)) return gcd_1;

    ll gcd_2 = arr[1];
    for (int i = 3; i < n; i += 2) {
        gcd_2 = __gcd(gcd_2, arr[i]);
    }

    if (isGoodGcd(gcd_2, arr, n)) return gcd_2;
    return 0;
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
        cout << paintArray(vec, n) << endl;
    }
    return 0;
}