//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    // TC = O((R - L) * D) length of string proportional to number = D
    // SC = O(D)
    int solve_brute(int L, int R, int X) {
        int ans = 0;
        for (int i = L+1; i < R; i++) {
            string str = to_string(i);
            char ch    = X + '0';
            for (int j = 0; j < str.length(); j++) {
                if (str[j] == ch) {
                    ans ++;
                }
            }
        }
        return ans;
    }
    
    // TC = O(R*log(R))
    // SC = O(1)
    int solve_optimal(int L, int R, int X) {
        int ans = 0;
        for (int i = L + 1; i < R; i++) {
            int curr = i;
            while(curr) {
                int rem = curr % 10;
                if (rem == X) ans ++;
                curr /= 10;
            }
        }
        return ans;
    }
  public:
    int countX(int L, int R, int X) {
        // return solve_brute(L, R, X);
        
        
        return solve_optimal(L, R, X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

// } Driver Code Ends