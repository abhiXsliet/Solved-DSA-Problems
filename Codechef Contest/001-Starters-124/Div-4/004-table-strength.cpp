// https://www.codechef.com/problems/STRONGTABLE



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> weight(n);
	    for (int i = 0; i < n; i++) {
	        cin >> weight[i];
	    }
	    sort(begin(weight), end(weight));
	    int ans = 0;
	    for (int i = 0; i < n; i++) {
	        int val = weight[i] * (n - i);
	        ans = max(ans, val);
	    }
	    cout << ans << endl;
	}
	return 0;
}
