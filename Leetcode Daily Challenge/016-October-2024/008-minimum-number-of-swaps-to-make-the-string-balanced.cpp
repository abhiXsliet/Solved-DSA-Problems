// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(string s) {
        int i = 0, j = 1;
        while (j < s.length()) {
            if (s[i] == '[' && s[j] == ']') {
                s.erase(i, 2);  // O(N)
                i --, j --;
                if (i < 0) {
                    i = j;
                    j = i + 1;
                }
            } else {
                i ++, j ++;
            }
        }
        return (s.length() + 2) / 4;
    }

    // TC : O(N) Where N = String length
    // SC : O(N)
    int better(string s) {
        stack<char> stk;
        for (char& ch : s) {
            if (stk.empty()) {
                stk.push(ch);
                continue;
            } else {
                if (stk.top() == '[' && ch == ']') {
                    stk.pop();
                } else {
                    stk.push(ch);
                }
            }
        }
        return (stk.size() + 2) / 4;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal_1(string s) {
        int n = s.length();
        int i = 0, j = i + 1;
        while (j < n) {
            if (i >= 0 && s[i] == '[' && s[j] == ']') {
                i --;
            } else {
                i ++;
                s[i] = s[j];
            }
            j ++;
        }
        int len = (i + 1) + 2;
        return (len / 4);
    }

    // TC : O(N)
    // SC : O(1)
    int optimal_2(string s) {
        int counter = 0;
        for (char& ch : s) {
            if (ch == '[') {    // counting just one type
                counter ++;
            } else if (counter > 0) {
                counter --;
            }
        }
        return (counter + 1) / 2;
    }
public:
    int minSwaps(string s) {
        // return brute(s);     // if found s[i] = '[' & s[j] = ']' remove from string 's'

        // return better(s);    // Using Stack

        // return optimal_1(s); // write using ptr = 'i' and read using ptr = 'j'

        return optimal_2(s);    // Using variable counter
    }
};