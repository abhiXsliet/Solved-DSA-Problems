// https://www.codechef.com/problems/FKMC



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
	    int count      = 0;
        int max_length = 0;
        int ones       = 0;
        for (char c : s) {
            if (c == '1') ones++;
            if (c == '0') {
                count++;
                max_length = max(max_length, count);
            } else {
                count = 0;
            }
        }
        cout << max_length + ones << endl;
	}
	return 0;
}
