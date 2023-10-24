// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1


//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if (s[i] == s[j]) {
                i++, j--;
            }
            else return false;
        }
        return true;
    }
    
    int solve_rec(string s, int n, int i) {
        if (i == n)
            return 0;
            
        int res = INT_MAX;
        
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                int cost = 1 + solve_rec(s, n, j+1);
                res = min(res, cost);
            }
        }
        
        return res;
    }
    
    
    int solve_mem(string s, int n, int i, vector<int>& dp) {
        if (i == n)
            return 0;
            
        if (dp[i] != -1)
            return dp[i];
            
        int res = INT_MAX;
        
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                int cost = 1 + solve_mem(s, n, j+1, dp);
                res = min(res, cost);
            }
        }
        
        return dp[i] = res;
    }
    
    int solve_tab(string s, int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
    
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    int cost = 1 + dp[j+1];
                    dp[i] = min(dp[i], cost);
                }
            }
        }
        return dp[0];
    }

public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        // return solve_rec(str, n, 0) - 1;
        
        
        //  vector<int> dp(n+1, -1);
        //  return solve_mem(str, n, 0, dp) - 1;
        
        
        return solve_tab(str, n) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends