// https://codeforces.com/problemset/problem/1682/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getMaximumX(vector<int>& nums, int n) {
    int xMax = -1;
    for (int i = 0; i < n; i ++) {
        if (i != nums[i]) {
            if (xMax == -1) xMax = nums[i];
            else xMax &= nums[i];
        }
    }
    return xMax;
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
        for (int &val : vec) cin >> val;
        cout << getMaximumX(vec, n) << endl;
    }
    return 0;
}