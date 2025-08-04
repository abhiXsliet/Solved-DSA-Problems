// https://codeforces.com/problemset/problem/1904/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> getScoreForEachElement(vector<ll> &vec, int n) {
    vector<pair<ll, ll>> store(n);
    for (int i = 0; i < n; i ++) {
        store[i] = {vec[i], i};
    }
    sort(begin(store), end(store));
    
    vector<ll> pSum(n);
    pSum[0] = store[0].first;
    for (int i = 1; i < n; i ++) {
        pSum[i] = (pSum[i - 1] + store[i].first);
    }

    vector<ll> result(n);
    for (int i = n - 1; i >= 0; i --) {
        ll idx  = store[i].second;
        
        int total = i;
        int j = i;
        while (j < n) {
            pair<ll, ll> temp = make_pair(pSum[j] + 1, INT_MIN);
            ll nextIdx = lower_bound(begin(store), end(store), temp) - begin(store);

            nextIdx --;
            if (nextIdx == j) break;

            total += (nextIdx - j);
            j = nextIdx;
        }

        result[idx] = total;
    }
    return result;
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
        
        vector<ll> ans = getScoreForEachElement(vec, n);
        for (ll &v : ans) cout << v << " ";
        cout << "\n";
    }
    return 0;
}