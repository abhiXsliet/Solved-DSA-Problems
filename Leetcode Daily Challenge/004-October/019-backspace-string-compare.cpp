// https://leetcode.com/problems/backspace-string-compare/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC = O(N)
    // SC = O(M + N)
    bool solve_brute(string s, string t) {
        string new_s = processedString(s);
        string new_t = processedString(t);

        return new_s == new_t;
    }

    string processedString(string str) {
        string result;
        for(char ch : str) {
            if (ch != '#') {
                result.push_back(ch);
            }else if (!result.empty()) {
                result.pop_back();
            }
        }
        return result;
    }

    // TC = O(N)
    // SC = O(1)
    bool solve_optimal(string s, string t) {
        int m = s.length();
        int n = t.length();

        int skip_s = 0;
        int skip_t = 0;

        int i = m -1;
        int j = n - 1;

        while (i >= 0 || j >= 0) {
            
            while(i >= 0) {
                if (s[i] == '#') {
                    skip_s++;
                    i--;
                }
                else if (skip_s > 0) {
                    skip_s--;
                    i--;
                }
                else break;
            }

            while (j >= 0) {
                if (t[j] == '#') {
                    skip_t++;
                    j--;
                }
                else if (skip_t > 0) {
                    skip_t--;
                    j--;
                }
                else break;
            }

            char first  = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];

            if (first != second) return false;

            i--;
            j--;
        }

        return true;
    }
public:
    bool backspaceCompare(string s, string t) {
        // return solve_brute(s, t);

        return solve_optimal(s, t);
    }
};