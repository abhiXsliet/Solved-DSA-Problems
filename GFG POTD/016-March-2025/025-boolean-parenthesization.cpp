// https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    int n;
    
    int solve(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp) {
        if (i == j) {
            if (isTrue) {
                return s[i] == 'T';
            } else {
                return s[i] == 'F';
            }
        }
        
        if (dp[i][j][isTrue] != -1) 
            return dp[i][j][isTrue];
        
        int ways = 0;
        for (int k = i + 1; k <= j - 1; k += 2) {
            
            int lT = solve(s, i, k - 1, 1, dp); // cnt true in left
            int lF = solve(s, i, k - 1, 0, dp); // cnt false in left
            int rT = solve(s, k + 1, j, 1, dp); // cnt true in right
            int rF = solve(s, k + 1, j, 0, dp); // cnt false in right
            
            if (s[k] == '|') {
                if (isTrue) {
                    ways += (lT * rT);  // true  | true  = true
                    ways += (lF * rT);  // false | true  = true
                    ways += (lT * rF);  // true  | false = true
                } else {
                    ways += (lF * rF);  // false | false = false
                }
            } else if (s[k] == '^') {
                if (isTrue) {
                    ways += (lT * rF);  // true  ^ false = true
                    ways += (lF * rT);  // false ^ true  = true
                } else {
                    ways += (lT * rT);  // true  ^ true  = false
                    ways += (lF * rF);  // false ^ false = false
                }
            } else if (s[k] == '&') {
                if (isTrue) {
                    ways += (lT * rT);  // true & true   = true
                } else {
                    ways += (lT * rF);  // true  & false = false
                    ways += (lF * rT);  // false & true  = false
                    ways += (lF * rF);  // false & false = false
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    
    // TC : O(N * N)
    // SC : O(N * N)
    int top_down(string &s) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solve(s, 0, n - 1, 1, dp);
    }
  public:
    int countWays(string &s) {
        n = s.length();
        
        return top_down(s);
        // return bottom_up(s);    // pending
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends