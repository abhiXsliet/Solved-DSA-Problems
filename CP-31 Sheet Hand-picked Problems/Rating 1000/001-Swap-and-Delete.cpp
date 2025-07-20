// https://codeforces.com/problemset/problem/1913/B



#include <bits/stdc++.h>
using namespace std;

int getZeroCount(string s) {
    int cnt = 0;
    for (char ch : s) {
        if (ch == '0') cnt++;
    }
    return cnt;
}
int solve(string s) {
    int n = s.length();
    int ans = 0;
    int zeroCnt = getZeroCount(s);
    int oneCnt  = n - zeroCnt;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            oneCnt -= 1;
        } else {
            zeroCnt -= 1;
        }
        if (oneCnt < 0 || zeroCnt < 0)
            return n - i;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
    return 0;
}