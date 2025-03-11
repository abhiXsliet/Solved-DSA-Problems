// https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int t[45];
    int approach_1(int n) {
        if (n <= 0) {
            return n == 0;
        }
        if (t[n] != -1) return t[n];
        return t[n] = approach_1(n - 1) + approach_1(n - 2);
    }
    
    // TC : O(N)
    // SC : O(N)
    int way_1(int n) {
        memset(t, -1, sizeof(t));
        return approach_1(n);
    }
    
    // TC : O(N)
    // SC : O(N)
    int way_2(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // TC : O(N)
    // SC : O(1)
    int way_3(int n) {
        int prev1 = 1, prev2 = 1;
        for (int i = 2; i <= n; i ++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
  public:
    int countWays(int n) {
        // return way_1(n);
        // return way_2(n);
        return way_3(n);
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends