// https://www.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1



//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  private:
    // TC : O(N)
    // SC : O(1)
    bool isPalindrome(string& str) {
        int start = 0, end = str.length() - 1;
        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    // TC : O(N^4)
    // SC : O(N)
    int brute(string& str) {
        int cnt = 0;
        set<string> st;
        for (int len = 1; len <= str.length(); len++) {
            for (int i = 0; i <= str.length() - len; i++) {
                string substr = str.substr(i, len);
                if (isPalindrome(substr) && st.find(substr) == st.end()) {
                    st.insert(substr);
                    cnt ++;
                }
            }
        }
        return cnt;
    }
    
    // TC : O(N^3)
    // SC : O(N)
    int better_1(string& str) {
        int cnt = 0;
        set<string> st;
        for (int i = 0; i < str.length(); i++) {
            string substr;
            // Second loop is generating sub-string
            for (int j = i; j < str.length(); j++) {
                substr += str[j];
                if (isPalindrome(substr) && st.find(substr) == st.end()) {
                    st.insert(substr);
                    cnt ++;
                }
            }
        }
        return cnt;
    }
    
    // TC : O(N)
    // SC : O(N^2)
    bool checkPalindrome(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return true;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == s[j]) {
            return dp[i][j] = checkPalindrome(s, i + 1, j - 1, dp);
        }
        return dp[i][j] = false;
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int better_2(string& str) {
        vector<vector<int>> dp(str.length()+1, vector<int>(str.length()+1, -1));
        int cnt = 0;
        set<string> st;
        for (int i = 0; i < str.length(); i++) {
            string substr;
            for (int j = i; j < str.length(); j++) {
                substr += str[j];
                if (checkPalindrome(str, i, j, dp) && st.find(substr) == st.end()) {
                    st.insert(substr);
                    cnt ++;
                }
            }
        }
        return cnt;
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int optimal_1(string& s) {
        int n = s.length();
        // dp[i][j] : substring starting from i and going till j is a palindrome or not?
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        set<string> st;
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0; len + i - 1 < n; i++) {
                int j = len + i - 1;
                
                if (i == j) { // single len string : 1-char only
                    dp[i][j] = 1;
                }
                else if (i + 1 == j) {  // 2-length string : 2-char only
                    dp[i][j] = (s[i] == s[j]);
                }
                else {  // 3,4,5... len string : then check prev string is a palindrome or not
                    dp[i][j] = ((s[i] == s[j]) && (dp[i + 1][j - 1]));
                }
                
                if (dp[i][j]) {
                    st.insert(s.substr(i, len));
                }
            }
        }
        return st.size();
    }
    
    // TC : O(N)
    void checkPalin(string& s, int n, int i, int j, set<string>& st) {
        while(i >= 0 && j < n && (s[i] == s[j])) {
            st.insert(s.substr(i, j-i+1));
            i --;
            j ++;
        }
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int optimal_2(string& s) {
        int n = s.length();
        set<string> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // Expanding (left, right) single char as center to find larger odd-length palindromic substrings.
            checkPalin(s, n, i, i, st);
            // Expanding (left, right) double char as center to find larger odd-length palindromic substrings.
            checkPalin(s, n, i, i+1, st);
        }
        return st.size();
    }
  public:
    int palindromeSubStrs(string s) {
        // return brute(s);    // O(N^4)
        
        // return better_1(s);    // O(N^3) 
        
        // return better_2(s);    // O(N^2)
        
        // return optimal_1(s);   // DP 
        
        return optimal_2(s);   // Expand from mid for odd and even case palindrome
    }
};


//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends