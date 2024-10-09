// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N) Where N = String 's' length
    int approach_1(string s) {
        stack<char> stk;
        for (char& ch : s) {
            if (stk.empty()) {
                stk.push(ch);
                continue;
            } else {
                if (stk.top() == '(' && ch ==  ')') {
                    stk.pop();
                } else {
                    stk.push(ch);
                }
            }
        }
        return stk.size();
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(string s) {
        int n = s.length();
        int i = 0, j = i + 1;
        while (j < n) {
            if (i >= 0 && s[i] == '(' && s[j] == ')') {
                i --;
            } else {
                i ++;
                s[i] = s[j];
            }
            j ++;
        }
        return (i + 1);
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(string s) {
        int count = 0;
        int open  = 0;
        for (char& ch : s) {
            if (ch == '(') {
                count ++;
            } else if (count > 0) {
                count --;
            } else {
                open ++;
            }
        }
        return count + open;
    }
public:
    int minAddToMakeValid(string s) {
        // return approach_1(s);    // Using Stack

        // return approach_2(s);   // String Modified : Using ptr 'i' for reading and ptr 'j' for writing;

        return approach_3(s);   // No String Modification
    }
};