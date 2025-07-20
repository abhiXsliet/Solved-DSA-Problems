// https://codeforces.com/problemset/problem/1438/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(vector<int> &vec, int n) {
    sort(begin(vec), end(vec));
    for (int i = 1; i < n; i ++) {
        if (vec[i] == vec[i - 1])
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int &v : vec) cin >> v;
        bool ans = isPossible(vec, n);
       if (ans) cout << "YES" << endl;
       else cout << "NO" << endl;
    }
    return 0;
}