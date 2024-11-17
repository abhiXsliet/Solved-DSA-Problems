#include <bits/stdc++.h>
using namespace std; 

pair<int,int> solve(vector<int>& arr, int k) {
    unordered_map<int, int> mpp;
    for (int& num : arr) {
        mpp[num] ++;
    }
    int K = k - 2;
    for (int i = 1; i <= sqrt(K); i ++) {
        if (K % i == 0) {
            // i, n/i
            int f1 = i, f2 = K / i;
            if (f1 == f2) {
                if (mpp[f1] == 2);
                    return {f1, f2};
            } else {
                if (mpp.count(f1) && mpp.count(f2)) 
                    return {f1, f2}; 
            }
        }
    }
    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i ++) {
            cin >> arr[i];
        }
        pair<int, int> ans = solve(arr, k);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}