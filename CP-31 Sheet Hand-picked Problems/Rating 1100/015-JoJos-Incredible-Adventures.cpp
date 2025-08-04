// https://codeforces.com/problemset/problem/1820/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMaxRectangleArea(string &s) {
    int n = s.length();
    if (n == 1) return s[0] == '1';
    
    bool onlyOnes = 1;
    for (int i = 0; i < n; i ++) {
        if (s[i] != '1') onlyOnes = false;
    }

    if (onlyOnes) return (1LL * n * n);

    string temp = s;
    s = s + temp;
    ll cntOnes = 0, cnt = 0;
    for (int i = 0; i < 2*n; i ++) {
        if (i > 0 && s[i] == '1' && s[i] == s[i - 1]) {
            cntOnes += 1;
        } else if (s[i] == '1') {
            cntOnes = 1;
        }
        cnt = max(cnt, cntOnes);
    }
    ll area = (((cnt + 1)/2) * ((cnt + 2)/2));  // crucial to find
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        string s;
        cin >> s;
        cout << getMaxRectangleArea(s) << endl;
    }
    return 0;
}