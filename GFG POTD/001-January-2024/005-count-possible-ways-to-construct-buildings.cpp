// https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int M = 1e9 + 7;
    long long solve_approach_1(int n) {
        vector<long long> dp(n, 0);
        dp[0] = 2;
        dp[1] = 3;
        
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] % M + dp[i - 2] % M;
        }
        return (((dp[n - 1] % M) * (dp[n - 1] % M)) % M);
    }
    
    // TC : O(N)
    // SC : O(1)
    long long solve_approach_2(int n) {
        long a = 1, b = 1, c = 0;
        for (long i = 1; i <= n; i++) {
            c = (a % M + b % M) % M;
            a =  b % M;
            b =  c % M;
        }
        return (int)((c*c) % M);
    }
	public:
	int TotalWays(int N) {
	   // return solve_approach_1(N);
	    
	    return solve_approach_2(N);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends