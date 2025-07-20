// https://codeforces.com/problemset/problem/1691/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isAscending(vector<ll> &arr, ll n) {
    bool ans = true;
    for (int i = 1; i < n; i ++) {
        if (arr[i] <= arr[i - 1]) {
            ans = false;
            break;
        }
    }
    return ans;
}

vector<ll> getValidOrder(vector<ll>& arr, ll n) {
    bool ascending = isAscending(arr, n);
    if (ascending) return {-1};

    unordered_map<ll, pair<int, int>> mpp;
    for (int i = 0; i < n; i ++) {
        if (mpp.count(arr[i])) {
            mpp[arr[i]].second = (i + 1);
        } else {
            mpp[arr[i]] = {(i + 1), (i + 1)};
        }
    }

    for (auto &it : mpp) {
        int start = it.second.first -  1;
        int end   = it.second.second - 1;
        if (start == end) return {-1};

        for (int i = start; i <= end; i ++) {
            arr[i] = (i + 1);
        }

        for (int i = start; i <= end; i ++) {
            swap(arr[i], arr[end]);
        }
    }

    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        ll n;
        cin >> n;
        vector<ll> shoeSize(n);
        for (ll &val : shoeSize) {
            cin >> val;
        }
        vector<ll> ans = getValidOrder(shoeSize, n);
        for (ll &val : ans) cout << val << " ";
        cout << endl;
    }
    return 0;
}