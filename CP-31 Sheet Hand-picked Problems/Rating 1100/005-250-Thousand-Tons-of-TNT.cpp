// https://codeforces.com/problemset/problem/1899/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; i ++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (n/i != i) {
                factors.push_back(n/i);
            }
        }
    }
    return factors;
}

ll getMaxGroupDiff(vector<ll> &vec, int k, int n) {
    int i = (k - 1);
    ll maxi = vec[i], mini = vec[i];
    i += k;
    while (i < n) {
        ll val = (vec[i] - vec[i - k]);
        maxi = max(maxi, val);
        mini = min(mini, val);
        i += k;
    }
    return (maxi - mini);
}

ll getMaximumDiffernce(vector<ll> &vec, int n) {
    vector<int> factors = getFactors(n);
    for (int i = 1; i < n; i ++) {
        vec[i] += vec[i - 1];
    }
    ll maxDiff = LONG_MIN;
    for (int &f : factors) {
        if (f == 1) continue;
        int groups = n / f;
        ll groupDiff = getMaxGroupDiff(vec, groups, n);
        maxDiff = max(maxDiff, groupDiff);
    }
    return (maxDiff == LONG_MIN) ? 0 : maxDiff;
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
        cout << getMaximumDiffernce(vec, n) << endl; 
    }
    return 0;
}