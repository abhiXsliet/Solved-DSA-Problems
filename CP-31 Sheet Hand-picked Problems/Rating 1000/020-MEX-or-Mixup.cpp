// https://codeforces.com/problemset/problem/1567/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getLen(int a, int b, vector<int> &xored) {
    // brute way of calculating xor till (a - 1);
    // int xor_ = 0;
    // for (int i = 0; i < a; i ++) {
    //     xor_ ^= i;
    // }

    // int xor_ = xored[a - 1]; // calcualted xor till (a - 1) before testcases

    int xor_;   // optimal way of calculating xor
    if ((a - 1) % 4 == 0) xor_ = (a - 1);
    if ((a - 1) % 4 == 1) xor_ = 1;
    if ((a - 1) % 4 == 2) xor_ = a;
    if ((a - 1) % 4 == 3) xor_ = 0;

    if (xor_ == b) return a;
    else if ((xor_ ^ b) != a) 
        return (a + 1);
    return (a + 2);
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 300000;
    vector<int> xored(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        xored[i] = (xored[i - 1] ^ i);
    }

    int t;
    cin >> t;
    while (t --) {
        int a, b;
        cin >> a >> b;
        cout << getLen(a, b, xored) << endl;
    }
    return 0;
}