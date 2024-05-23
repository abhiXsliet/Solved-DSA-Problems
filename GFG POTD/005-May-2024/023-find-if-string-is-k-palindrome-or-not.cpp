// https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // TC : O(N * N)
    // SC : O(N * N)
    int solve(int l, int r, string& str,vector<vector<int>>&dp){

        if(l>=r)return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        if(str[l] == str[r])
            return dp[l][r]= solve(l+1, r-1, str,dp);

        return dp[l][r] = min(solve(l+1 , r , str,dp),solve(l,r-1,str,dp))+1;                       

    }
public:
 int kPalindrome(string str, int n, int k){
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return k >= solve(0, n-1, str, dp);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends