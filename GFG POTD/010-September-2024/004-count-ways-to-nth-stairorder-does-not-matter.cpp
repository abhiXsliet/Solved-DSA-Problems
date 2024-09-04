// https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
    // TC : O(N)
    // SC : O(N)
    int solve_1(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        int val = 2;
        for (int i = 3; i <= n+1; i += 2) {
            dp[i]     = val ++;
            dp[i - 1] = dp[i];
        }
        return dp[n];
    }
    
    // TC : O(1)
    // SC : O(1)
    int solve_2(int n) {
        (n / 2) + 1; 
    }
	public:
	int nthStair(int n){
        // return solve_1(n);
        
        return solve_2(n);
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
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends