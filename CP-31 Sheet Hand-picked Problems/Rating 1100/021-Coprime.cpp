// https://codeforces.com/problemset/problem/1742/D




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getMaxIdxSum(vector<int> &vec, int n) {
    unordered_map<int, vector<int>> mpp;
    for (int i = 0; i < n; i ++) mpp[vec[i]].push_back(i);
    int ans = -1;
    for (int i = 1000; i >= 1; i --) {
        for (int j = i; j >= 1; j --) {
            if ((__gcd(i, j) == 1)) {
                if (mpp.count(i) && mpp.count(j)) {
                    int sumIdx = mpp[i].back() + mpp[j].back() + 2;
                    ans = max(ans, (sumIdx));
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int &v : vec) cin >> v;
        cout << getMaxIdxSum(vec, n) << endl;
    }
    return 0;
}