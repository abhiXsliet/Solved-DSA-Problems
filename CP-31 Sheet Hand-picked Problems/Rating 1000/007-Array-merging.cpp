// https://codeforces.com/problemset/problem/1831/B




#include <bits/stdc++.h>
using namespace std;

int longestSubarrayLen(vector<int> &a, vector<int> &b, int n) {
    unordered_map<int, int> mpp;
    int maxLen = 1;

    int val = -1, cnt = 0;
    for (int &num : a) {
        if (num == val) cnt += 1;
        else {
            val = num;
            cnt = 1;
        }
        mpp[val] = max(mpp[val], cnt);
        maxLen = max(maxLen, mpp[val]);
    }

    val = -1, cnt = 0;
    for (int &num : b) {
        if (val == num) cnt += 1;
        else {
            val = num;
            cnt = 1;
        }
        maxLen = max(maxLen, (cnt + mpp[val]));
    }
    return maxLen;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i ++) {
            cin >> b[i];
        }

        cout << longestSubarrayLen(a, b, n) << endl;
    }
    return 0;
}