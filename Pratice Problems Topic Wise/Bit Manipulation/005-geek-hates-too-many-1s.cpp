// https://www.geeksforgeeks.org/problems/geek-hates-too-many-1s--170647/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    // TC : O(1)
    // SC : O(1)
    int noConseBits(int n) {
        for (int i = 31; i >= 0; i--) {
            if ( (n & (1 << i)) > 0 && (n & (1 << i - 1)) > 0 && (n & (1 << i - 2)) > 0) {
                
                n = n ^ (n & (1 << i - 2));
            }
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends