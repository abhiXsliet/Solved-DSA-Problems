// https://codeforces.com/problemset/problem/1659/A




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string getString(int n, int r, int b) {
    string res = "";
    
    int availableRegion = (b + 1);
    int groups = (r / (availableRegion));
    int extra  = (r % (availableRegion));
    
    while (res.length() < n) {
        res += string(groups, 'R');
        if (extra) {
            res += 'R';
            extra --;
        }
        if (b) {
            res += 'B';
            b --;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t --) {
        int n, r, b;
        cin >> n >> r >> b;
        cout << getString(n, r, b) << endl;
    }
    return 0;
}