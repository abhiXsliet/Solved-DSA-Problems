// https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    // TC : O(N)
    // SC : O(N)
    int solve(int n) {
        if (n == 0) return 0;
        
        int a = n/2;
        int b = n/3;
        int c = n/4;
        
        if (a + b + c <= n)
            return n;
        
        return solve(a) + solve(b) + solve(c);
    }
    public:
    int maxSum(int n)
    {
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
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends