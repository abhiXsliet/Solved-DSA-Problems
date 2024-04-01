// https://www.codechef.com/problems/ANTITRI



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, l;
    cin>>n>>l;
   
    if (l >= 2000) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    else {
        ll val = 1;
        cout << val << " ";
        for (int i = 1; i < n; i++) {
            cout << val + l << " ";
            val = val + l;
        }
        cout << endl;
        return;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	   solve();
	}
	return 0;
}
