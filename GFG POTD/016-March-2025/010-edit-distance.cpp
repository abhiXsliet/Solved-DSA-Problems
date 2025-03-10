// https://www.geeksforgeeks.org/problems/edit-distance3702/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int m, n;
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i >= m) return (n - j);
        if (j >= n) return (m - i);
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if (s1[i] == s2[j]) {
            ans = solve(s1, s2, i + 1, j + 1, dp);
        } else {
            int rem = 1 + solve(s1, s2, i, j + 1, dp);
            int ins = 1 + solve(s1, s2, i + 1, j, dp);
            int rep = 1 + solve(s1, s2, i + 1, j + 1, dp);
            ans = min({rem, ins, rep});
        }
        
        return dp[i][j] = ans;
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int approach_1(string &s1, string &s2) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(s1, s2, 0, 0, dp);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int approach_2(string &s1, string &s2) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; j ++) {
            dp[m][j] = (n - j);
        }
        for (int i = 0; i <= m; i ++) {
            dp[i][n] = (m - i);
        }
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                int ans = 0;
                if (s1[i] == s2[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int rem = 1 + dp[i][j + 1];
                    int ins = 1 + dp[i + 1][j];
                    int rep = 1 + dp[i + 1][j + 1];
                    ans = min({rem, ins, rep});
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    // TC : O(M * N)
    // SC : O(N)
    int approach_3(string &s1, string &s2) {
        // transforming s1 into s2 that's why choose n as size not m
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        for (int j = 0; j < n; j ++) {
            prev[j] = (n - j);
        }
        
        for (int i = m - 1; i >= 0; i --) {
            curr[n] = (m - i);  // catch
            for (int j = n - 1; j >= 0; j --) {
                int ans = 0;
                if (s1[i] == s2[j]) {
                    ans = prev[j + 1];
                } else {
                    int rem = 1 + curr[j + 1];
                    int ins = 1 + prev[j];
                    int rep = 1 + prev[j + 1];
                    ans = min({rem, ins, rep});
                }
                
                curr[j] = ans;
            }
            prev = curr;
        }
        return curr[0];
    }
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        m = s1.length(), n = s2.length();
        
        // return approach_1(s1, s2);
        // return approach_2(s1, s2);
        return approach_3(s1, s2);
    }
};

//{ Driver Code Starts.
int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends