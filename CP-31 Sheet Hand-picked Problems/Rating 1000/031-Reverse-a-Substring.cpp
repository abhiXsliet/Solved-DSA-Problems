// https://codeforces.com/problemset/problem/1155/A




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<string, pair<int, int>> solve(string &s, int n) {
    stack<pair<char, int>> stk;
    int idx1 = -1, idx2 = -2;
    bool flag = 0;
    for (int i = 0; i < n; i ++) {
        while (!stk.empty() && stk.top().first > s[i]) {
            idx1 = stk.top().second;
            idx2 = i;
            flag = 1;
            stk.pop();
        }
        if (flag) break;
        stk.push({s[i], i});
    }
    if (!flag) return {"NO", {idx1, idx2}};
    return {"YES", {(idx1 + 1), (idx2 + 1)}};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // pair<string, pair<int, int>> ans = solve(s, n);
    // cout << ans.first << "\n";
    // int idx1 = ans.second.first;
    // int idx2 = ans.second.second;
    // if (idx1 != -1 && idx2 != -1) cout << idx1 << " " << idx2 << endl;

    bool flag = 0;
    for (int i = 0; i < n - 1; i ++) {
        if (s[i] > s[i + 1]) {
            cout << "YES" << endl;
            cout << (i + 1) << " " << (i + 2) << endl;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << "NO" << endl;
    return 0;
}