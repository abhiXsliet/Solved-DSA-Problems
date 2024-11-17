#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] == -1) {
            swap(arr[i], arr[i - 1]);
        }
    }
    return is_sorted(begin(arr), end(arr));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool ans = solve(arr, n);
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}