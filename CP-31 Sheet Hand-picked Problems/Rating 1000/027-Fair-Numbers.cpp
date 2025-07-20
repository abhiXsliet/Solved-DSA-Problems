// https://codeforces.com/problemset/problem/1411/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isFair(ll num) {
    ll newNum = num;
    while (newNum) {
        int d = newNum % 10;
        if (d != 0 && num % d) return false;
        newNum /= 10;
    }
    return true;
}

ll getFairNum(ll n) {
    for (int i = 0; i <= 2520; i ++) {
        ll num = i + n;
        if (isFair(num)) return num;
    }
    return (n + (ll)2520);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        ll n;
        cin >> n;
        cout << getFairNum(n) << endl;
    }
    return 0;
}