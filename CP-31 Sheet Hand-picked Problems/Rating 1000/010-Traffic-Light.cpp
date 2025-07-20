// https://codeforces.com/problemset/problem/1744/C



#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int binarySearch(vector<int> &store, int tarI) {
    int low = 0, high = store.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (store[mid] >= tarI) {
            ans = store[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int getMinTimeToCrossRoad(string &s, int n, char &ch) {
    if (ch == 'g') return 0;

    vector<int> store;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'g') {
            store.push_back(i);
        }
    }

    int minTime = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == ch) {
            int idx = binarySearch(store, i);   // next optimal idx for 'g'
            int time = 0;
            if (idx >= i) {
                time = (idx - i);
            } else {
                if (!store.empty()) {
                    time = (n - i + store[0]);
                } else {
                    time = 0;
                }
            }

            minTime = max(minTime, time);
        }
    }
    return minTime;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        char ch;
        cin >> ch;
        string s;
        cin >> s;
        cout << getMinTimeToCrossRoad(s, n, ch) << endl;
    }
    return 0;
}