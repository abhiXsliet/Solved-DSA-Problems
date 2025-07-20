// https://codeforces.com/problemset/problem/1506/C




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getLongestCommonString(string &a, string &b) {
    unordered_set<string> st;

    for (int i = 0; i < a.length(); i ++) {
        for (int j = i; j < a.length(); j ++) {
            string s = a.substr(i, j - i + 1);
            st.insert(s);
        }
    }

    string res;

    for (int i = 0; i < b.length(); i ++) {
        for (int j = i; j < b.length(); j ++) {
            string s = b.substr(i, j - i + 1);
            if (st.count(s)) {
                if (res.length() < s.length()) {
                    res = s;
                }
            }
        }
    }

    int del1 = a.length() - res.length();
    int del2 = b.length() - res.length();

    return (del1 + del2); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        string a, b;
        cin >> a >> b;
        cout << getLongestCommonString(a, b) << endl;
    }
    return 0;
}