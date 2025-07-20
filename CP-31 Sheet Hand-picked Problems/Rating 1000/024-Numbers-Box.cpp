// https://codeforces.com/problemset/problem/1447/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int maxSum(vector<vector<int>> &mat, int m, int n) {
    int cntZeros = 0, cntNegatives = 0, total = 0, mini = INT_MAX;
    for (auto& v : mat) {
        for (int &e : v) {
            if (e == 0) cntZeros += 1;
            else if (e < 0) cntNegatives += 1;

            mini = min(mini, abs(e));
            total += abs(e);
        }
    }

    if (cntNegatives % 2) {
        return (total - 2*mini);
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        int m, n;
        cin >> m >>  n;
        vector<vector<int>> mat(m, vector<int>(n));
        for (auto& v : mat) {
            for (int &e : v) {
                cin >> e;
            }
        }
        cout << maxSum(mat, m, n) << endl;
    }
    return 0;
}