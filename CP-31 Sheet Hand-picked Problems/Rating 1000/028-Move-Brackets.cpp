// https://codeforces.com/problemset/problem/1374/C




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int minOpr(string &s, int n) {
    string res;
    for (char &ch : s) {
        if (!res.empty() && res.back() == '(' && ch == ')') res.pop_back();
        else res.push_back(ch);
    }
    return res.size() / 2;
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
        string s;
        cin >> s;
        cout << minOpr(s, n) << endl;
    }
    return 0;
}