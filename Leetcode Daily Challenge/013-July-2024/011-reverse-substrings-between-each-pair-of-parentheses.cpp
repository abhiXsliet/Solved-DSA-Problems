// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N) Where N = Length of string 's'
    string approach_1(string s) {
        stack<char> stk;
        int n = s.length();
        for (char& ch : s) {
            if (ch == '(' || islower(ch)) {
                stk.push(ch);

            } else {    // ')'
                string poppedStr;
                while (stk.top() != '(') {
                    poppedStr += stk.top();
                    stk.pop();
                }

                if (stk.top() == '(') stk.pop();

                for (char& pCh : poppedStr) {
                    stk.push(pCh);
                }
            }
        }

        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }
public:
    string reverseParentheses(string s) {
        return approach_1(s);   // Using Stack
    }
};