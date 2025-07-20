// https://codeforces.com/problemset/problem/1312/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        for (int &val : vec) cin >> val;

        sort(rbegin(vec), rend(vec));
        
        for (int &val : vec) cout << val << " ";
        cout << "\n";
    }
    return 0;
}