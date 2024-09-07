// https://www.geeksforgeeks.org/problems/nth-natural-number/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // TC : O(log(N))
    // SC : O(1)
    long long findNth(long long n) {
        long long base = 1;
        long long ans  = 0;
        
        while (n) {
            long long rem = n % 9;
            ans += rem * base;
            base *= 10;
            n /= 9;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}
// } Driver Code Ends