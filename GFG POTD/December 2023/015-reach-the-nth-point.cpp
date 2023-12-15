// https://www.geeksforgeeks.org/problems/reach-the-nth-point5433/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
        int M = 1e9 + 7;
        
        // TC : O(N+N) ~ O(N)
        // SC : O(N)
        int solve_mem(int n, vector<int>& dp) {
            if (n == 1) return 1;
            if (n == 2) return 2;
            
            if (dp[n] != -1) return dp[n];
            
            int ans = (solve_mem(n - 1, dp) + solve_mem(n - 2, dp)) % M;
            
            return dp[n] = ans;
        }
        
        // TC : O(N)
        // SC : O(N)
        int solve_tab(int n) {
            vector<int> dp(n+1, 0);
            dp[1] = 1;
            dp[2] = 2;
            
            for (int i = 3; i <= n; i++) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % M;
            }
            
            return dp[n];
        }
        
        // TC : O(N)
        // SC : O(1)
        int solve_so(int n) {
            if (n == 1) return 1;
            if (n == 2) return 2;
            
            int prev_prev = 1;
            int prev      = 2;
            int curr      = 0;
            
            for (int i = 3; i <= n; i++) {
                curr = (prev_prev + prev) % M;
                prev_prev = prev;
                prev      = curr;
            }
            
            return curr;
        }
	public:
		int nthPoint(int n){
		  //  vector<int> dp(n+1, -1);
		  //  return solve_mem(n, dp);
		  
		  //  return solve_tab(n);
		  
		    return solve_so(n);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends