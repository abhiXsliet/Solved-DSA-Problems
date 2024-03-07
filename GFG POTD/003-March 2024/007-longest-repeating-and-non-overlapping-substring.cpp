// https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    // TC : O(N^2)
    // SC : O(N^2)
    string solve_tab(string& s, int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        int maxSubstringLen = 0;
        int index           = -1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                
                if (j - i > dp[i - 1][j - 1] && s[i - 1] == s[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxSubstringLen) {
                        maxSubstringLen = dp[i][j];
                        index           = max(index, i);
                    }
                }
                else dp[i][j] = 0;
            }
        }
        
        string res;
        if (maxSubstringLen > 0) {
            for (int i = index - maxSubstringLen + 1; i <= index; i++) {
                res += s[i - 1];
            }   
        }
        
        return res.size() == 0 ? "-1" : res;
    }
  public:
    string longestSubstring(string s, int n) {
        return solve_tab(s, n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends