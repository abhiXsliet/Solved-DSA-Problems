// https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(string &digits, int i, vector<int>& dp) {
        if (i >= n) return 1;
        
        if (dp[i] != -1) return dp[i];
        
        int ans = 0;
        if (digits[i] != '0') 
            ans += solve(digits, i + 1, dp);
        
        int val = INT_MAX;
        if (i + 1 < n) val = stoi(digits.substr(i, 2));
        
        if (val >= 10 && val <= 26)
            ans += solve(digits, i + 2, dp);
            
        return dp[i] = ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    int top_down(string &digits) {
        vector<int> dp(n + 1, -1);
        return solve(digits, 0, dp);
    }

    // TC : O(N)
    // SC : O(N)
    int bottom_up(string &digits) {
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i --) {
            int ans = 0;
            if (digits[i] != '0') 
                ans += (i + 1 >= n) ? 1 : dp[i + 1];
            
            int val = INT_MAX;
            if (i + 1 < n) val = stoi(digits.substr(i, 2));
            
            if (val >= 10 && val <= 26)
                ans += (i + 2 >= n) ? 1 : dp[i + 2];
                
            dp[i] = ans;
        }
        return dp[0];
    }
    
    // TC : O(N)
    // SC : O(1)
    int space_optimized(string &digits) {
        int prev1 = 0, prev2 = 0;
        for (int i = n - 1; i >= 0; i --) {
            int ans = 0;
            if (digits[i] != '0') 
                ans += (i + 1 >= n) ? 1 : prev1;
            
            int val = INT_MAX;
            if (i + 1 < n) val = stoi(digits.substr(i, 2));
            
            if (val >= 10 && val <= 26)
                ans += (i + 2 >= n) ? 1 : prev2;
                
            int curr = ans;
            prev2    = prev1;
            prev1    = curr;
        }
        return prev1;
    }
  public:
    int countWays(string &digits) {
        n = digits.length();
        
        // return top_down(digits);
        // return bottom_up(digits);
        return space_optimized(digits);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends