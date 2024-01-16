// https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
private:
    // TC : O(2^n)
    // SC : O(n) -> Recursive Depth
    // Going from back to front in recursive way
    int solve_rec(int m, int n) { 
        if (n == 0) 
            return 1;
            
        if (m < n) 
            return 0;
        
        int include = solve_rec(m / 2, n - 1);  // since a(i+1) = 2 * a(i)
        int exclude = solve_rec(m - 1, n);
        
        return (include + exclude);
    }
    
    // TC : O(m*n)
    // SC : O(m*n)
    int dp[101][101];
    int solve_mem(int m, int n) { 
        if (n == 0) 
            return 1;
            
        if (m < n) 
            return 0;
            
        if (dp[m][n] != -1) return dp[m][n];
        
        int include = solve_mem(m / 2, n - 1);  // since a(i+1) = 2 * a(i)
        int exclude = solve_mem(m - 1, n);
        
        return dp[m][n] = (include + exclude);
    }
    
    // TC : O(2^m)
    // SC : O(m) 
    // Going from front to back in recursive way
    int solve_rec_2(int m, int n, int i , int j) {
        if (j == n) return 1; 
        if (i  > m) return 0;
        
        int include = solve_rec_2(m, n, 2*i, j+1);
        int exclude = solve_rec_2(m, n, i+1, j);
        
        return (include + exclude);
    }
public:
    int numberSequence(int m, int n){
        // return solve_rec(m, n);
        
        // memset(dp, -1, sizeof(dp));
        // return solve_mem(m, n);
        
        
        return solve_rec_2(m, n, 1, 0);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends