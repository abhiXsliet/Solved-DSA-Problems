// https://codeforces.com/problemset/problem/1832/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMaxSum(vector<ll> &vec, int n, int k) {
    sort(begin(vec), end(vec));
    for (int i = 1; i < n; i ++) vec[i] += vec[i - 1];

    ll maxSum = 0;
    for (int operation1 = 0; operation1 <= k; operation1 ++) {
        int operation2 = (k - operation1);

        int deletedEleFront = (2 * operation1);
        int deletedEleBack  = (n - 1 - operation2);
        
        ll leftDeletedSum  = (deletedEleFront - 1) >= 0 ? vec[deletedEleFront - 1] : 0;
        
        ll remainingEleSum  = (vec[deletedEleBack] - leftDeletedSum);

        maxSum = max(maxSum, remainingEleSum);
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n, k;
        cin >> n >> k;
        vector<ll> vec(n);
        for (ll &val : vec) {
            cin >> val;
        }
        cout << getMaxSum(vec, n, k) << endl;
    }
    return 0;
}