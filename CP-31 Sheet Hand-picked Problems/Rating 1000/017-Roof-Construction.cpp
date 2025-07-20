// https://codeforces.com/problemset/problem/1632/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> getSequence(int n) {
    int msb = log2(n - 1);
    int val = pow(2, msb) - 1;
    vector<int> ans;
    for (int i = val; i >= 0; i --) {
        ans.push_back(i);
    }
    val = pow(2, msb);
    for (int i = val; i < n; i ++) {
        ans.push_back(i);
    }
    return ans;
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
        vector<int> ans = getSequence(n);
        for (int &v : ans) cout << v << " ";
        cout << "\n";
    }
    return 0;
}