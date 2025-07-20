// https://codeforces.com/problemset/problem/1876/A




#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;  // {resid, cost}
using ll = long long;

ll getMinCost(int r, int c, vector<int> &resid, vector<int> &cost) {
    if (r == 1) return c;

    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 0; i < r; i ++) {
        pq.push({cost[i], resid[i]});
    }

    ll ans = 0;
    bool isFirst = true;
    while (!pq.empty() && r > 0) {
        int cost = pq.top().first;
        int cntResid = pq.top().second;
        pq.pop();

        
        if (cost >= c) break;
        
        if (isFirst) {  // cost for sharing info to only one resident
            ans += c;   
            r --;
            isFirst = false;
        }
        
        ll remResid = min(cntResid, r);
        ans += (remResid * (ll)cost);
        r   -= remResid;
    }

    ans += ((ll)r * c);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        int r, c;
        cin >> r >> c;
        vector<int> resid(r);
        for (int i = 0; i < r; i ++) {
            cin >> resid[i];
        }
        vector<int> cost(r);
        for (int i = 0; i < r; i ++) {
            cin >> cost[i];
        }

        cout << getMinCost(r, c, resid, cost) << endl;
    }
    return 0;
}