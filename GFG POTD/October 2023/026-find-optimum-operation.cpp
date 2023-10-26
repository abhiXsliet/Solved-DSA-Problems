// https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  private:
    int t[1000001];
    
    // TC = pow(2, n)
    // SC = O(n) -> recursive depth
    int solve_recursion(int n) {
        if (n == 0) 
            return 0;
        
        int op1 = INT_MAX;
        if (n % 2 == 0)
            op1 = 1 + solve_recursion(n / 2);
            
        int op2 = 1 + solve_recursion(n - 1);
        
        return min(op1, op2);
    }
    
    // TC = O(n * n)
    // SC = O(n)
    int solve_memoization(int n) {
        if (n == 0) 
            return 0;
        
        if (t[n] != -1)
            return t[n];
        
        int op1 = INT_MAX;
        if (n % 2 == 0)
            op1 = 1 + solve_memoization(n / 2);
            
        int op2 = 1 + solve_memoization(n - 1);
        
        return t[n] = min(op1, op2);
    }
    
    // TC = O(log(N))
    // SC = O(1)
    int solve(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int steps = 2;
        
        while(n > 2) {
            if (n % 2 == 0) 
                n /= 2;
                
            else n--;
            
            // one liner if-else
            // n = n % 2 == 0 ? n/2 : n-1;
            
            steps ++;
        }
        return steps;
    }
  public:
    int minOperation(int n)
    {
        // return solve_recursion(n);
        
        // memset(t, -1, sizeof(t));
        // return solve_memoization(n);
        
        return solve(n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends