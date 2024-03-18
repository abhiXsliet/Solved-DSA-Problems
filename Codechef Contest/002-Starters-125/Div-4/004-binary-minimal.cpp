// https://www.codechef.com/problems/BILM



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n, k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    
	    int cntOnes = 0;
	    for (char& ch : s) {
	        if (ch == '1') 
	            cntOnes ++;
	    }
	    
	    if (k >= cntOnes) {
	        int len = n - k;
	        string newS(len, '0');
	        cout << newS << endl;
	    }
	    else {
	        for (int i = 0; i < n; i++) {
	            if (k == 0) break;
	            if (s[i] == '1') {
	                s[i] = '0';
	                k --;       // one operations used
	            }
	        }
	        cout << s << endl;
	    }
	}
	return 0;
}
