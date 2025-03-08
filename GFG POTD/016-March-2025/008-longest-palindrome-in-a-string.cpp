// https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int expandedPalindromeLen(string &s, int i, int j) {
        int n = s.length();
        while (i >= 0 && j < n && s[i] == s[j]) {
            i --, j ++;
        }
        return j - i - 1;
    }
    
    // TC : O(N) but O(1) after the first call for a given pair
    // SC : O(N) Recursive Call Stack Space
    bool isPalindrome(string &s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = (s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1, dp) : false;
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    string approach_1(string &s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        int maxPalinLen = 1;
        int maxPalinIdx = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                if (isPalindrome(s, i, j, dp)) {
                    if (j - i + 1 > maxPalinLen) {
                        maxPalinLen = (j - i + 1);
                        maxPalinIdx = i;
                    }
                }
            }
        }
        return s.substr(maxPalinIdx, maxPalinLen);
    }
    
    // TC : O(N^2)
    // SC : O(1)
    string approach_2(string &s) {
        int n = s.length();
        int maxPalinLen = 1;
        int maxPalinIdx = 0;
        for (int i = 0; i < n - 1; i ++) {
            int len1 = expandedPalindromeLen(s, i, i);       // expand around i for odd length
            int len2 = expandedPalindromeLen(s, i, i + 1);   // expand around i, i+1 for even length
    
            int curr_max = max(len1, len2);
            if (curr_max > maxPalinLen) {
                maxPalinLen = curr_max;
                maxPalinIdx = i - ((curr_max) - 1) / 2;
            }
        }
        return s.substr(maxPalinIdx, maxPalinLen);
    }
  public:
    string longestPalindrome(string &s) {
        // return approach_1(s);    // DP : memoized palindrome check fn. 
        return approach_2(s);    // Expand around center
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends