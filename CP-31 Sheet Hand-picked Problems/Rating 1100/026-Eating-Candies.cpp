// https://codeforces.com/problemset/problem/1669/F




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll getTotalConsumedCandies(vector<int> &vec, int n) {
    int i = 0, j = n - 1, sumI = vec[i], sumJ = vec[j];
    int totalMax = 0;
    while (i < j) {
        if (sumI == sumJ) {
            totalMax = max(totalMax, (i + 1 + n - j));
            i ++, j --;
            if (i < j) sumI += vec[i];
            if (j > i) sumJ += vec[j];
        } else if (sumI < sumJ) {
            i ++;
            if (i < j) sumI += vec[i];
        } else {
            j --;
            if (j > i) sumJ += vec[j];
        }
    }
    return totalMax;
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
        for (int &wt : vec) cin >> wt;
        cout << getTotalConsumedCandies(vec, n) << endl;
    }
    return 0;
}