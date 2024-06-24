// https://www.geeksforgeeks.org/problems/summed-matrix5834/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(1)
    // SC : O(1)
    long long sumMatrix(long long n, long long q) {
        long long ans = 0;
        if (n + 1 == q) ans = n;
        else if (n + 1 > q){
            long long val = (n + 1) - q;
            ans = (n - val);
        } else {
            long long val = q - (n + 1);
            ans = (n - val);
        }
        return ans <= 0 ? 0 : ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends