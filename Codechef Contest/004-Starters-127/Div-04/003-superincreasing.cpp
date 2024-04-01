// https://www.codechef.com/problems/SUPINC


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k, x;
    cin>>n>>k>>x;
    if (k > 30) {
        cout << "No" << "\n";
        return;
    }
    
    ll res = 1 << (k - 1);
    if (res <= x) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

void solve_2() {
    ll n, k, x;
    cin>>n>>k>>x;
    
    ll sum = 0;
    ll val = 1;
    for (int i = 1; i < k; i++) {
        sum += val;
        val = sum + 1;
        if (sum >= x) {
            cout << "No" << endl;
            return;
        }
    }
    if (sum < x) cout << "Yes" << endl;
    else cout << "No" << endl;
}

void solve_3() {
    ll n, k, x;
    cin>>n>>k>>x;
    
    vector<int> a{1};
    while(a.size() < k) {
        ll sum = 0;
        for (auto& i : a) {
            sum += i;
        }
        a.push_back(sum + 1);
        if (sum + 1 > x) break;
    }
    cout << ((a.back() <= x) ? "Yes" : "No") << "\n";
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	   solve();

	   //solve_2();
	   
	   //solve_3();
	}
	return 0;
}
