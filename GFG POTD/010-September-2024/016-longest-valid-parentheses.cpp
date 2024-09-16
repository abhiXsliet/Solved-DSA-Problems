// https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    bool isValid(string& s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') 
                stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
    
    // TC : O(N^3)
    // SC : O(N)
    int brute(string& s) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                
                int len = j - i + 1;
                string newStr = s.substr(i, len); // substring from [i...j]
                if ( isValid(newStr) ) {
                    maxLen = max(maxLen, j - i + 1);
                }
                
            }
        }
        return maxLen;
    }
    
    // TC : O(N)
    // SC : O(N)
    int better(string& s) {
        int n = s.length();
        
        int maxLen = 0;
        stack<int> stk;
        stk.push(-1);
        
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    maxLen = max(maxLen, i - stk.top());
                } else {
                    stk.push(i);    // to track the new substr
                }
            }
        }
        
        return maxLen;
    }
    
    // TC : O(N)
    // SC : O(1)
    int optimal(string& s) {
        int n = s.length();
        int left = 0, right = 0;
        int maxLen = 0;
    
        // Left to right traversal
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
    
            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (right > left) {
                left = right = 0;  // reset counters if invalid
            }
        }
    
        // Reset the counters and traverse from right to left
        left = right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
    
            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            } else if (left > right) {
                left = right = 0;  // reset counters if invalid
            }
        }
    
        return maxLen;

    }
  public:
    int maxLength(string& str) {
        // DP --> PENDING ??
        
        // return brute(str);    // Using stack
        
        // return better(str);   // Using stack & caculating maxValidParenthesis on the go
    
        return optimal(str);  // using openBr, closeBr variables
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
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends