// https://leetcode.com/problems/valid-parenthesis-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int t[101][101];

    // TC : O(N * N) Where N is the length of the string
    // SC : O(N * N) Total Visting States
    bool solve_mem(string& s, int i, int open_br, int n) {
        if (i == n) return open_br == 0;

        if (t[i][open_br] != -1) 
            return t[i][open_br];

        bool isValid = false;

        if (s[i] == '(') {
            isValid |= solve_mem(s, i + 1, open_br + 1, n);
        }
        else if (s[i] == '*') {
            isValid |= solve_mem(s, i + 1, open_br + 1, n);       // '('
            isValid |= solve_mem(s, i + 1, open_br, n);           // ''
            if (open_br > 0) 
                isValid |= solve_mem(s, i + 1, open_br - 1, n);   // ')'
        }
        else if (open_br > 0) {
            isValid |= solve_mem(s, i + 1, open_br - 1, n);
        }

        return t[i][open_br] = isValid;
    }

    // TC : O(N * N) Where N is the length of the string
    // SC : O(N * N) Total Visting States
    bool solve_tab(string& s, int n) {
        // dp[i][open_br] : string starting from ith index and with a cnt of open_br, is valid or not
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, 0));

        // at nth index if open_br cnt == 0 then its true
        dp[n][0] = true;

        bool isValid = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int open_br = 0; open_br <= n; open_br++) {
                bool isValid = false;

                if (s[i] == '(') {
                    isValid |= dp[i + 1][open_br + 1];
                }
                else if (s[i] == '*') {
                    isValid |= dp[i + 1][open_br + 1];       // '('
                    isValid |= dp[i + 1][open_br];           // ''
                    if (open_br > 0) 
                        isValid |= dp[i + 1][open_br - 1];   // ')'
                }
                else if (open_br > 0) {
                    isValid |= dp[i + 1][open_br - 1];
                }

                dp[i][open_br] = isValid;
            }
        }
        // at 0th index and 0-cnt of open_br
        return dp[0][0];
    }

    // TC : O(N)
    // SC : O(N)
    bool solve_3(string& s, int n) {
        stack<int> open_br; // store indices of open brackets
        stack<int> asterix; // store indices of asterix

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open_br.push(i);
            }
            else if (s[i] == '*') {
                asterix.push(i);
            }
            else if (s[i] == ')') {
                if (!open_br.empty()) {
                    open_br.pop();
                }
                else if (!asterix.empty()){
                    asterix.pop();
                }
                else return false;
            }
        }

        while(!open_br.empty() && !asterix.empty()) {
            if (open_br.top() < asterix.top()) {        // "((((****"
                open_br.pop();
                asterix.pop();
            }
            else return false;
        }

        return open_br.empty();
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_4(string& s, int n) {
        int open_br = 0;    // L ---> R Traversal
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') {
                open_br ++;
            }
            else {
                open_br --;
                if (open_br < 0) return false;
            }
        }
        
        int close_br = 0; // L <----- R Traversal
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                close_br ++;
            }
            else {
                close_br --;
                if (close_br < 0) return false;
            }
        }
        
        return true;
    }
public:
    bool checkValidString(string s) {
        // memset(t, -1, sizeof(t));
        // return solve_mem(s, 0, 0, s.length());

        // return solve_tab(s, s.length());
        
        // return solve_3(s, s.length());  // STACK

        return solve_4(s, s.length());
    }
};