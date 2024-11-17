// https://codeforces.com/contest/2037/problem/A


#include <bits/stdc++.h>
using namespace std; 

int solve(vector<int>& arr, int n) {
    unordered_map<int, int> mpp;
    for (int& num : arr) {
        mpp[num] ++;
    }
    int ans = 0;
    for (auto &it : mpp) {
        if (it.second > 1) {
            ans += (it.second) / 2;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
        }
        int ans = solve(arr, n);
        cout << ans << endl;
    }
    return 0;
}