// https://leetcode.com/problems/count-and-say/




#include <bits/stdc++.h>   
using namespace std;

class Solution {
private:
    string countAndSay(string &s) {
        int n = s.length();
        char number = s[0];
        int cntNum  = 1;
        string result;
        for (int i = 0; i < n; i ++) {
            if (i + 1 < n && s[i] == s[i + 1]) {
                cntNum += 1;
            } else {
                result += (to_string(cntNum) + number);
                if (i + 1 < n) {
                    number = s[i + 1];
                    cntNum = 1;
                }
            }
        }
        return result;
    }

    // TC : O(N * Len)
    // SC : O(N + Len) N = Recursive Stack Space and Len = longest sequence formed by countAndSay fn.
    string approach_1(int n) {
        if (n == 1) return "1";

        string res = approach_1(n - 1);
        return countAndSay(res);
    }

    // TC : O(N * Len)
    // SC : O(Len)
    string approach_2(int n) {
        string base = "1";
        while (n -- > 1) {
            string countS = countAndSay(base);
            base = countS;
        }
        return base;
    }
public:
    string countAndSay(int n) {
        // return approach_1(n);    // Recursively
        return approach_2(n);    // Iteratively
    }
};