// https://www.codechef.com/problems/TRISWP



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    int cnt  = n - 2;    // total no. of distinct strings possible after rotation
	    bool flg = 0;
	    
	    for (int i = 0; i+2 < n; i++) {
	        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) { // aaa, bbb
	            flg = 1;
	            cnt --;
	        }
	        // s1, s2, s4 are  : not create a different string eg.,
	        // 1st rotation : aada -> adaa
	        // 2nd rotation : aada -> adaa  // remains same 
	        else if (i + 3 < n && s[i] == s[i + 1] && s[i + 1] == s[i + 3]) {
	            cnt --;
	        }
	    }
	    
	    cout << cnt + flg << endl;
	}
}
