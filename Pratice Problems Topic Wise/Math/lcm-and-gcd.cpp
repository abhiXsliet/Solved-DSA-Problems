// https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    typedef long long ll;
    
    ll gcd(ll A, ll B) {
        if (A == 0) return A;
        if (B == 0) return B;
        
        while (A != B) {
            if (A > B) {
                A -= B;
            } else {
                B -= A;
            }
        }
        return A;
    }
    
    ll gcdFast(ll A, ll B) {
        if (B == 0) 
            return A;
            
        return (A, A % B);
    }
    
    ll lcm(ll A, ll B) {
        return (A / gcd(A, B)) * B;
    }
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        return { lcm(A, B), gcd(A, B) };
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends