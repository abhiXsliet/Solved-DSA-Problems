// https://www.geeksforgeeks.org/problems/recursive-sequence1611/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    typedef long long ll;
    int MOD = 1e9 + 7;
    
    // TC : O(N * N)
    // SC : O(1)
    ll approach_1(int n) {
        if (n == 0) return 0;
        
        
        ll term = 1;
        for (int i = n * (n - 1) / 2 + 1; i <= n * (n + 1) / 2; i++) {
            
            term = (term * i) % MOD;
        }
        
        return (approach_1(n - 1) + term) % MOD;
    }
    
    // TC : O(N * N)
    // SC : O(1)
    ll approach_2(int n) {
        ll ans = 1;
        int k = 2;
        for (int i = 2; i <= n; i++) {
            ll term = 1;
            for (int j = 1; j <= i; j++) {
                term = (term * k) % MOD;
                k ++;
            }
            
            ans = (ans + term) % MOD;
        }
        return ans;
    }
public:
    long long sequence(int n){
        // return approach_1(n);
        
        return approach_2(n);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends