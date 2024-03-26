// https://www.codechef.com/problems/TRIO



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> A(n);
	    for(int i=0; i < n; i++) {
	        cin>>A[i]; 
	    }
	    
	    ll pairCnt = 0;
	    unordered_map<int, int>mpp;
	    
	    // for every A[i] check : A[j] => 3*A[i]/(A[i] - 1) exists or not
	    for (int& num : A) {
	        if ( num>1 && (3*num)%(num-1) == 0 ) {
	            pairCnt += mpp[(3*num)/(num-1)];
	        }
	        mpp[num] ++;
	    }
	    cout << pairCnt << "\n";
	}
}
