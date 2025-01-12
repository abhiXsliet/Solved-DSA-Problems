// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    bool approach_1(string &s, string &locked) {
        int n = s.length();
        if (n % 2) return false;
        stack<int> open;        // stores the indices of open bracket only
        stack<int> openClose;   // stores the indices of locked[i] == 0 brackets

        for (int i = 0; i < n; i ++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    open.push(i);
                } else if (!open.empty()) {
                    open.pop();
                } else if (!openClose.empty()) {
                    openClose.pop();
                } else {
                    return false;
                }
            } else if (locked[i] == '0') {
                openClose.push(i);
            }
        }

        while (!open.empty() && !openClose.empty()) {
            if (open.top() < openClose.top()) {
                open.pop();
                openClose.pop();
            } else {
                return false;
            }
        }
        
        return open.empty();
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_2(string &s, string &locked) {
        int n = s.length();
        if (n % 2) return false;
        
        int open = 0, close = 0;   
        // locked[i] == '0' will be counted for both close and open
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(' || locked[i] == '0') 
                open += 1;
            else 
                open -= 1;
            if (open < 0) return false;
        }
        for (int i = n - 1; i >= 0; i --) {
            if (s[i] == ')' || locked[i] == '0') 
                close += 1;
            else 
                close -= 1;
            if (close < 0) return false;
        }
        return true;
    }
public:
    bool canBeValid(string s, string locked) {
        // return approach_1(s, locked);
        return approach_2(s, locked);
    }
};