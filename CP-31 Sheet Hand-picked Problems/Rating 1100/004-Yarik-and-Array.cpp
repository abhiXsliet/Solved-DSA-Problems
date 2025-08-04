// https://codeforces.com/problemset/problem/1899/C




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Kadanes Algorithm
ll getMaximumSumSubArray(vector<ll>& vec, int n) {
    int i = 0, j = 1;
    bool prevParity = (vec[i] % 2);
    ll maxSum = vec[0], prev = vec[0];
    while (j < n) {
        bool currParity = (vec[j] % 2);

        if (currParity != prevParity) {
            prev = max(prev + vec[j], vec[j]);
            prevParity = currParity;
        } else {
            i = j;
            prev = vec[i];
            prevParity = (vec[i] % 2);
        }
        
        maxSum = max(maxSum, prev);
        j ++;
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<ll> vec(n);
        for (ll &val : vec) cin >> val;
        
        cout << getMaximumSumSubArray(vec, n) << endl;
    }
    return 0;
}