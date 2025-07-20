// https://codeforces.com/problemset/problem/1620/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxArea(int w, int h, vector<int>& h1, vector<int> &h2, vector<int> &v1, vector<int> &v2) {
    int maxH1 = h1.back() - h1[0];
    int maxH2 = h2.back() - h2[0];
    
    ll valH = max(maxH1, maxH2) * (ll)h;

    int maxV1 = v1.back() - v1[0];
    int maxV2 = v2.back() - v2[0];

    ll valV = max(maxV1, maxV2) * (ll)w;

    return max(valH, valV);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;

        int k1;
        cin >> k1;
        vector<int> h1(k1);
        for (int &val : h1) {
            cin >> val;
        }

        int k2;
        cin >> k2;
        vector<int> h2(k2);
        for (int &val : h2) {
            cin >> val;
        }

        int k3;
        cin >> k3;
        vector<int> v1(k3);
        for (int &val : v1) {
            cin >> val;
        }

        int k4;
        cin >> k4;
        vector<int> v2(k4);
        for (int &val : v2) {
            cin >> val;
        }

        cout << maxArea(w, h, h1, h2, v1, v2) << "\n";
    }
    return 0;
}
