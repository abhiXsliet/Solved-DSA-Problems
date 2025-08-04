// https://codeforces.com/problemset/problem/1631/B




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int minOpr(vector<int> &arr, int n) {
    int cntOpr = 0;
    int i = n - 1;

    while (i > 0) {
        if (arr[i] == arr[i - 1]) {
            i --;
            continue;
        }

        i -= (n - i);
        if (i >= 0) arr[i] = arr[n - 1];
        cntOpr += 1;
    }

    return cntOpr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &val : arr) cin >> val;
        cout << minOpr(arr, n) << endl;
    }
    return 0;
}