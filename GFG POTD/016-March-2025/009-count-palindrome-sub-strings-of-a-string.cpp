// https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int t[1001][1001];
    
    // TC : O(N)
    // SC : O(1)
    int countPalindrome(string &s, int i, int j) {
        int n = s.length();
        int cntPalindrome = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            cntPalindrome += 1;
            i --, j ++;
        }
        return cntPalindrome;
    }

    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        if (t[i][j] != -1) return t[i][j];
        
        return t[i][j] = (s[i] == s[j]) ? isPalindrome(s, i + 1, j - 1) : false;
    }
    
    // TC : O(N^2)
    // SC : O(N)
    int approach_1(string &s, int n) {
        memset(t, -1, sizeof(t));
        int cntPalindrome = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                if (isPalindrome(s, i, j)) {
                    cntPalindrome += 1;
                }
            }
        }
        return cntPalindrome - n;
    } 
    
    // TC : O(N^2)
    // SC : O(1)
    int approach_2(string &s, int n) {
        int cntPalindrome = 1;
        for (int i = 0; i < n - 1; i ++) {
            int oddLen  = countPalindrome(s, i, i);       // get palindrome cnt i for odd length
            int evenLen = countPalindrome(s, i, i + 1);   // get palindrome cnt i, i+1 for even length
    
            cntPalindrome += (oddLen + evenLen);
        }
        return cntPalindrome - n;
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int approach_3(string &s, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // dp[i][j] == 1 ? palindrome [i:j] : not palindrome
        int cntPalindrome = 0;
        for (int L = 1; L <= n; L ++) {
            
            for (int i = 0; L + i - 1 < n; i ++) {
                
                int j = L + i - 1;
                if (i == j) {   // single chars palindrome
                    dp[i][j] = 1;
                } else if (i + 1 == j) {    // double chars
                    dp[i][j] = (s[i] == s[j]);
                } else {    // more than two chars
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                
                if (dp[i][j]) cntPalindrome += 1;
            }
        }
        return cntPalindrome - n;
    }
  public:
    int countPS(string &s) {
        // return approach_1(s, s.length());    // similar as longest palindromic substring, where palindrome check get memoized (since appending only new char to the previous one)
        // return approach_2(s, s.length());    // Expand from center and cnt for even and odd length of palindrome
    
        return approach_3(s, s.length());   // Bottom Up - Blueprint for palindrome related problems
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends