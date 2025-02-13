// https://leetcode.com/problems/clear-digits/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isChar(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    // TC : O(N^2)
    // SC : O(1)
    string approach_1(string s) {
        int i = 0;
        while (i < s.length()) {
            if (i + 1 < s.length() && isChar(s[i]) && isDigit(s[i + 1])) {
                s.erase(i, 2);
                i = 0;
            } else i ++;
        }
        return s;
    }

    // TC : O(N)
    // SC : O(1)
    string approach_2(string s) {
        int i = 1;
        while (i < s.length()) {
            if (i - 1 >= 0 && isChar(s[i - 1]) && isDigit(s[i])) {
                s.erase(i - 1, 2);
                i --;
            } else i ++;
        }
        return s;
    }

    // TC : O(N)
    // SC : O(N)
    string approach_3(string s) {
        stack<char> stk;
        for (char &ch : s) {
            if (stk.empty() || isChar(ch)) {
                stk.push(ch);
            } else {
                if (!stk.empty() && isDigit(ch)) {
                    stk.pop();
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

    // TC : O(N)
    // SC : O(1)
    string approach_4(string s) {
        string result;
        for (char &ch : s) {
            if (result.empty() || isChar(ch)) {
                result.push_back(ch);
            } else {
                if (!result.empty() && isDigit(ch)) {
                    result.pop_back();
                }
            }
        }
        return result;
    }
public:
    string clearDigits(string s) {
        // return approach_1(s);   // BRUTE
        // return approach_2(s);   // OPTIMAL : input modified
        // return approach_3(s);   // OPTIMAL : using stack
        return approach_4(s);   // OPTIMAL : input not modified
    }
};