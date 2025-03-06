// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int t[1001][1001];
    // TC : O(N^2)
    // SC : O(N^2) total states but recursive call stack space = O(N + M)
    int approach_1(string &s1, string &s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length())
            return 0;
            
        if (t[i][j] != -1) return t[i][j];
          
        int match = 0;  
        if (s1[i] == s2[j]) {
            match = 1 + approach_1(s1, s2, i + 1, j + 1);
        } 
        int noMatch = max(approach_1(s1, s2, i + 1, j), approach_1(s1, s2, i, j + 1));
    
        return t[i][j] = max(match, noMatch);
    }
    
    // TC : O(N^2)
    // Sc : O(N^2)
    int way_1(string &s1, string &s2) {
        memset(t, -1, sizeof(t));
        return approach_1(s1, s2, 0, 0);
    }

    // TC : O(N^2)
    // Sc : O(N^2)
    int way_2(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                int match = 0;  
                if (s1[i] == s2[j]) {
                    match = 1 + dp[i + 1][j + 1];
                } 
                int noMatch = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(match, noMatch);
            }
        }
        
        return dp[0][0];
    }

    // TC : O(N^2)
    // Sc : O(N)
    int way_3(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                int match = 0;  
                if (s1[i] == s2[j]) {
                    match = 1 + prev[j + 1];
                } 
                int noMatch = max(prev[j], curr[j + 1]);
                curr[j] = max(match, noMatch);
            }
            prev = curr;
        }
        
        return curr[0];
    }
    
    vector<char> printLCS(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                int match = 0;  
                if (s1[i] == s2[j]) {
                    match = 1 + dp[i + 1][j + 1];
                } 
                int noMatch = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(match, noMatch);
            }
        }
        
        
        vector<char>lcs(dp[0][0]);
        int idx = lcs.size() - 1;
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (s1[i] == s2[j] && dp[i][j] == 1 + dp[i + 1][j + 1]) {
                    lcs[idx --] = s2[j];
                    break;
                }
            }
        }
        // for (auto& c : lcs) cout << c << " ";
        // cout << endl;
        return lcs;
    }
  public:
    int lcs(string &s1, string &s2) {
        // return way_1(s1, s2);   // Top-Down
        // return way_2(s1, s2);   // Bottom-Up
        return way_3(s1, s2);   // Bottom-Up : Space Optimized
        // printLCS(s1, s2);    // printing of lcs by tracing back
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends