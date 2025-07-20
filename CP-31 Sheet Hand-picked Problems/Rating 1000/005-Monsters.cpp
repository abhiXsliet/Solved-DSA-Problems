// https://codeforces.com/problemset/problem/1849/B



#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> getIndicesOrder(vector<int> &monsters, int n, int k) {
    auto cmp = [&](P a, P b) {
        if (a.first == b.first) 
            return a.second > b.second;
        return a.first < b.first;
    };

    priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < n; i ++) {
        int val = monsters[i];
        if (val > k) {
            if (val % k == 0) {
                val = k;
            } else {
                val = val % k;
            }
        }
        pq.push({val, (i + 1)});
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        ll n, k;
        cin >> n >> k;
        vector<int> monsters(n);
        for (int i = 0; i < n; i ++) {
            cin >> monsters[i];
        }

        vector<int> order = getIndicesOrder(monsters, n, k);
        for (int &i : order) cout << i << " ";
        cout << endl;
    }
    return 0;
}