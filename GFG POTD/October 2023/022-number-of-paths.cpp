// https://practice.geeksforgeeks.org/problems/number-of-paths0926/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    const int mod = 1000000007;
    typedef long long ll;
    private:
    ll modInverse(ll a, int m) {
        return modPow(a, m - 2, m);
    }
    
    ll modPow(ll base, int exp, int mod) {
        ll result = 1;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    public:
    long long  numberOfPaths(int M, int N)
    {
        int n = M + N - 2;
        int r = M - 1;
        ll ans = 1;
        
        for (int i = 1; i <= r; i++) {
            ans = (ans * (n - i + 1)) % mod;
            ans = (ans * modInverse(i, mod)) % mod;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends