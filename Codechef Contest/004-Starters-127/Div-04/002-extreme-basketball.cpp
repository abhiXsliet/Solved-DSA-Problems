// https://www.codechef.com/problems/BBWIN



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int a, b;
	    cin>>a>>b;
	    long long ans = 0;
	    if (a >= b+10)
	    { 
	        ans = 0; 
	    }
	    else 
	    {
	        int m = (b + 10) - a;
	        ans = (m + 2) / 3;  // ceil
	    }
	    cout << ans << endl;
	}
}