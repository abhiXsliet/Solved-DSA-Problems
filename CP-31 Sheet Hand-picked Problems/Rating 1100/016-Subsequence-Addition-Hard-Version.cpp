// https://codeforces.com/problemset/problem/1807/G2




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossibleToGenerateArray(vector<ll> &vec, int n) {
    if (n == 1) return vec[0] == 1;
    sort(begin(vec), end(vec));
    ll sum = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i] > sum) {
            return false;
        }
        sum += vec[i];
    }
    return true;
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
        if (isPossibleToGenerateArray(vec, n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}