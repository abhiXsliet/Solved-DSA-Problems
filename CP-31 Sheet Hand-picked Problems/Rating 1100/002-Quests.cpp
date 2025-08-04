// https://codeforces.com/problemset/problem/1914/C




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getMaxExperience(int n, int k, vector<int> &a, vector<int> &b) {
    int sum  = a[0], maxi = b[0], ans = a[0];
    for (int i = 1; i <= min(k, n); i ++) {
        
        int val = sum + maxi * (k - i);
        ans = max(ans, val);
        
        if (i < n) {
            sum += a[i];
            maxi = max(maxi, b[i]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t;
    cin >> t;
    while (t --) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &val : a) cin >> val;
        for (int &val : b) cin >> val;
        cout << getMaxExperience(n, k, a, b) << endl;
    }
    return 0;
}