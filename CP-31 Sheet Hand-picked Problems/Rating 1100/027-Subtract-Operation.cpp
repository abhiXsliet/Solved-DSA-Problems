// https://codeforces.com/problemset/problem/1656/B




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossibleToAchieveK(vector<ll> &vec, ll n, ll k) {
    map<int, bool> mpp;
    for (ll &val : vec) mpp[val] = 1;
    for (ll &val : vec) {
        if (mpp.count(val - k)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        ll n, k;
        cin >> n >> k;
        vector<ll> vec(n);
        for (ll &val : vec) cin >> val;
        if (isPossibleToAchieveK(vec, n, k)) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    return 0;
}