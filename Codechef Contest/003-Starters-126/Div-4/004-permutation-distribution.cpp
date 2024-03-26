// https://www.codechef.com/problems/PERDIS



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> arr(n, 0);
	    for(int i=0; i<n; i++) {
	        cin>>arr[i];
	    }
	    int ans = 0;
	    for (int i = 0; i < n; i++) {
	        if (arr[i] == i + 1) {
	            ans ++;
	            i++;
	        }
	    }
	    cout << ans << "\n";
	}
}