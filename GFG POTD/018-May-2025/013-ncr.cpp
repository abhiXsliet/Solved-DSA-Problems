// https://www.geeksforgeeks.org/problems/ncr1019/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        
        // To minimize the number of steps, compute C(n, min(r, n-r))
        if (r > n - r) r = n - r;
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res *= (n - r + i);
            res /= i;
        }
        
        return (int)res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends