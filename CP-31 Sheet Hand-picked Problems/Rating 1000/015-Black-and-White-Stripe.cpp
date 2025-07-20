// https://codeforces.com/problemset/problem/1690/D




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getChangeRequired(string &s, int n, int k) {
    int i = 0, j = 0;
    int minLen = INT_MAX, cntZero = 0;
    while (j < n) {
        cntZero += (s[j] == 'W') ? 1 : 0;
        if (j - i + 1 > k) {
            cntZero -= (s[i] == 'W') ? 1 : 0;
            i ++;
        }
        if (j - i + 1 == k) {
            minLen = min(minLen, cntZero);
        }
        j ++;
    }
    return minLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << getChangeRequired(s, n, k) << endl;
    }
    return 0;
}