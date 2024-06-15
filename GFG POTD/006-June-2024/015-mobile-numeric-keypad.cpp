// https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    typedef long long ll;
    
    // TC : O(N*10) ~= O(N)
    // SC : O(N*10) ~= O(N)
    ll tab(int n) {
        vector<vector<ll>> dp(n + 1, vector<ll> (10, 0));
        for (int j = 0; j < 10; j ++) {
            dp[1][j] = 1;
        }
        
        vector<vector<int>> validPath {
            {0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6}, 
            {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9},
            {4, 7, 8}, {5, 7, 8, 0, 9}, {6, 8, 9}
        };
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 0; j < 10; j ++) {
                for (int& k : validPath[j]) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        
        ll ans = 0;
        for (int j = 0; j < 10; j ++) {
            ans += dp[n][j];
        }
        return ans;
    }
  public:
    long long getCount(int n) {
        return tab(n);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}
// } Driver Code Ends