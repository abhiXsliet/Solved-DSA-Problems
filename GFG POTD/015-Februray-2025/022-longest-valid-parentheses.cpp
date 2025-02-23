// https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    bool isValid(string &s) {
        stack<char> stk;
        for (char &ch : s) {
            if (ch == '(') {
                stk.push(ch);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
    
    // TC : O(N^3)
    // SC : O(N)
    int brute(string &s) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                int len =  j - i + 1;
                string newStr = s.substr(i, len);
                if (isValid(newStr)) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }

/*
    1. Push the index of each opening parenthesis onto the stack.
    2. On closing parenthesis, pop the stack. If empty, push the current index as a base.
    3. Otherwise, update maxLength as current index - top of stack.
*/
    // TC : O(N)
    // SC : O(N)
    int better(string &s) {
        int n = s.length();
        stack<int> stk;
        stk.push(-1);
        int maxLen = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    maxLen = max(maxLen, i - stk.top());
                } else {
                    stk.push(i);    // to track new substr
                }
            }
        }
        return maxLen;
    }

/*    
    -- Left to Right:
    1. Track open and close counts for '(' and ')' respectively
    2. When open == close, update max length.
    3. Reset open & clsoe to zero if close > open.
    
    -- Right to Left:
    1. Track open and close counts for '(' and ')' respectively
    2. When open == close, update max length.
    3. Reset open & clsoe to zero if close > open.
*/
    // TC : O(N)
    // SC : O(1)
    int optimal(string &s) {
        int n = s.length();
        int maxLen = 0;
        int open = 0, close = 0;
        // Traverse left to right
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') open ++;
            else close ++;
            
            if (open == close) {
                maxLen = max(maxLen, 2*close);
            } else if (close > open) {
                open = close = 0;
            }
        }
        
        open = close = 0;
        // Traverse right to left
        for (int i = n - 1; i >= 0; i --) {
            if (s[i] == '(') open ++;
            else close ++;
            
            if (open == close) {
                maxLen = max(maxLen, 2*close);
            } else if (open > close) {
                open = close = 0;
            }
        }
        return maxLen;
    }
  public:
    int maxLength(string& s) {
        // return brute(s);
        // return better(s);
        return optimal(s);
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

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends