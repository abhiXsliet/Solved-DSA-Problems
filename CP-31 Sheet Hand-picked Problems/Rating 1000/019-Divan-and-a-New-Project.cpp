// https://codeforces.com/problemset/problem/1614/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, vector<int>> solve(int n, vector<int> &vec) {
    vector<pair<int, int>> store;
    for (int i = 0; i < n; i ++) {
        store.push_back({vec[i], (i + 1)});
    }

    int len = n / 2;
    vector<int> coordinates(n + 1, 0);
    for (int i = 1; i <= len; i ++) {
        coordinates[i] = i;
        if (n % 2) 
            coordinates[n - i] = -i;
        else coordinates[n - i + 1] = -i;
    }
    if (n % 2) coordinates[n] = (n + 1) / 2;
    
    vector<pair<int, int>> dist(n);
    for (int i = 1; i <= n; i ++) {
        dist[i - 1] = {2*abs(coordinates[i]), coordinates[i]};
    }
    
    sort(rbegin(store), rend(store));   // most frequent visit building at first
    sort(begin(dist), end(dist));

    ll time = 0;
    for (int i = 0; i < n; i ++) {
        time += ((ll)store[i].first * dist[i].first);
        coordinates[store[i].second] = (dist[i].second);
    }

    return {time, coordinates};
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

        vector<int>vec(n);
        for (int &val : vec) {
            cin >> val;
        }

        pair<ll, vector<int>> getVal = solve(n, vec);
        cout << getVal.first << "\n";
        for (int &val : getVal.second) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}