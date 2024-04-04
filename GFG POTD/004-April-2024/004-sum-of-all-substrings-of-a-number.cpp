// https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    typedef long long ll;
    int M = 1e9+7;
    
    // TC : O(N)
    // SC : O(N)
    ll solve_1(string& s, int n) {
        vector<ll> dp(n, 0LL);
        dp[0] = s[0] - '0';
        ll ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = (((s[i] - '0') * (i + 1)) % M + (dp[i - 1] * 10) % M) % M;
            ans = (ans + dp[i]) % M;
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    ll solve_2(string& s, int n) {
        ll prev = s[0] - '0';
        ll ans  = prev;
        for (int i = 1; i < n; i++) {
            ll curr = (((s[i] - '0') * (i + 1)) % M + (prev * 10) % M) % M;
            prev    = curr;
            ans     = (ans + prev) % M;
        }
        return ans;
    }
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        // return solve_1(s, s.length());
        
        return solve_2(s, s.length());
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends