// https://codeforces.com/problemset/problem/1821/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> getLongestSubarray(vector<int> &a, vector<int> &b, int n) {
    int l = 0;
    for (; l < n; l ++) {
        if (a[l] != b[l]) break;
    }
    int r = n - 1;
    for (; r >= 0; r --) {
        if (a[r] != b[r]) break;
    }

    for (;l > 0;) {
        if (b[l - 1] <= b[l]) l --;
        else break;
    }
    for (;r < n - 1;) {
        if (b[r + 1] >= b[r]) r ++;
        else break;
    }

    return {(l + 1), (r + 1)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &val : a) cin >> val;
        for (int &val : b) cin >> val;
        pair<int, int> ans = getLongestSubarray(a, b, n);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}