// https://codeforces.com/problemset/problem/1891/B




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> getUpdatedArr(vector<ll>& a, vector<ll> &b, int n, int q) {
    unordered_set<int> st;
    for (ll &query : b) {
        if (st.count(query)) continue;
        st.insert(query);
        for (ll &val : a) {
            if ((val % (1 << query)) == 0) {
                val += (1 << (query - 1));
            }
        }
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t;
    cin >> t;
    while (t --) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n), b(q);
        for (ll &val : a) cin >> val;
        for (ll &val : b) cin >> val;
        vector<ll> ans = getUpdatedArr(a, b, n, q);
        for (ll &v : ans) cout << v << " ";
        cout << "\n";
    }
    return 0;
}