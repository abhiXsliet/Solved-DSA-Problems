// https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
        typedef long long int ll;
	public:
	    // TC : O(log(N))
	    // SC : O(1)
		ll PowMod(ll x, ll n, ll M)
		{
		    ll res = 1;
		    while(n > 0) {
		        if (n & 1) {  // odd
		            res = ((res) % M * (x) % M) % M;
		        }
		        x = ((x) % M * (x) % M) % M;
		        n >>= 1;
		    }
		    return res;
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends