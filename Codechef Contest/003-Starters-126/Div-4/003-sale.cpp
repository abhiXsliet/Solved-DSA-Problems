// https://www.codechef.com/problems/FINALSALE



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> arr(n, 0);
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        vector<ll> pSum(n, arr[0]);
        for (int i = 1; i < n; i++) {
            pSum[i] = pSum[i - 1] + arr[i];
        }
        ll total_sales = pSum[n - 1];
        for(int i = n-1; i >= 0; i--) {
            total_sales = max(total_sales, pSum[i] + arr[i]);
        }
        cout << total_sales << endl;
    }
    return 0;
}
