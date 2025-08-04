// https://codeforces.com/problemset/problem/1797/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isIdenticalAfterRotation(vector<vector<ll>>& mat, ll n, ll k) {
    if (n == 1) return true;

    ll cntOpr = 0;
    for (int i = 0; i < n/2; i ++) {
        for (int j = 0; j < n; j ++) {
            if (mat[i][j] != mat[n - i - 1][n - j - 1]) {
                cntOpr += 1;
            }
        }
    }

    // check for the middle row in odd case
    if (n % 2) {
        int row = n/2;
        for (int j = 0; j < n/2; j ++) {
            if (mat[row][j] != mat[row][n - j - 1]) {
                cntOpr += 1;
            }
        }
    }

    k -= cntOpr;
    if (n % 2) return (k >= 0);
    return (k >= 0 && k % 2 == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> mat(n, vector<ll>(n));
        for (vector<ll> &vec : mat) {
            for (ll &val : vec) {
                cin >> val;
            }
        }
        if(isIdenticalAfterRotation(mat, n, k)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}