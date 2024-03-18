// https://www.codechef.com/problems/NGRS



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int x, y;
	    cin>>x>>y;
	    if (x < 50) cout << "Z" << endl;
	    else if (y < 50 && x >= 50) cout << "F" << endl;
	    else cout << "A" << endl;
	}
	return 0;
}
