// https://codeforces.com/problemset/problem/1791/D




#include <bits/stdc++.h>
using namespace std;

int getMaxVal(string &s, int n) {
    unordered_map<char, int> aMpp, bMpp;
    for (char &ch : s) {
        bMpp[ch] ++;
    }

    int maxVal = bMpp.size();
    for (char &ch : s) {
        aMpp[ch] ++;
        bMpp[ch] --;
        if (!bMpp[ch]) bMpp.erase(ch);
        int len = (aMpp.size() + bMpp.size());
        maxVal = max(maxVal, len);
    }
    return maxVal;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << getMaxVal(s, n) << endl;
    }
    return 0;
}