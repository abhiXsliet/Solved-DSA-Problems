// https://codeforces.com/problemset/problem/1791/G1




#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll getMaxTeleporters(vector<ll> &vec, ll n, ll c) {
    auto cmp = [&](P a, P b) {
        if (a.first == b.first) {
            return b.second < a.second;
        }
        return a.first > b.first;
    };
    priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i ++) {
        pq.push({(vec[i] + i + 1), (i + 1)});
    }

    ll cnt = 0;
    while (!pq.empty() && pq.top().first <= c) {
        c -= pq.top().first;
        pq.pop();
        cnt += 1;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, c;
        cin >> n >> c;
        vector<ll> vec(n);
        for (ll &val : vec) cin >> val;
        cout << getMaxTeleporters(vec, n, c) << endl;
    }
    return 0;
}