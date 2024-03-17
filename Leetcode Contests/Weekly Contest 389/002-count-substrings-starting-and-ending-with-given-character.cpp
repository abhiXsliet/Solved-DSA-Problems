// https://leetcode.com/contest/weekly-contest-389/problems/count-substrings-starting-and-ending-with-given-character/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N^3) -> TLE
    // SC : O(N)
    ll solve_brute(string s, char c) {
        int n = s.length();
        // count of substrings whose first and last char equal to c
        ll cntSubstr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string substr = s.substr(i, j - i + 1);
                if (substr[0] == c && substr[substr.length()-1] == c) {
                    cntSubstr ++;
                }
            }
        }
        return cntSubstr;
    }

    // TC : O(N)
    // SC : O(N)
    ll solve_better(string s, char c) {
        int n = s.length();
        vector<int> prefix(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                prefix[i] = (i > 0 ? prefix[i - 1] : 0) + 1;
            } else if (i > 0) {
                prefix[i] = prefix[i - 1];
            }
        }

        // count of substrings whose first and last char equal to c
        ll cntSubstr = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                cntSubstr += prefix[i];
            }
        }
        return cntSubstr;
    }

    // TC : O(N)
    // SC : O(1)
    ll solve_optimal_1(string s, char c) {
        int n = s.length();
        // count of substrings whose first and last char equal to c
        ll cntSubstr = 0;        
        // keep track of previous char which is equal to c
        int count = 0; 
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                cntSubstr += 1 + count;
                count ++;
            } 
        }
        return cntSubstr;
    }

    // TC : O(N)
    // SC : O(1)
    // combination ncr where r = 2 since first and last char should be equal to c
    ll solve_optimal_2(string s, char c) {
        int n = s.length();
        // count c in s
        ll c_cnt = 0;
        for (char& ch : s) {
            if (ch == c) 
                c_cnt ++;
        }

        return c_cnt*(c_cnt - 1) / 2 + c_cnt; // +c_cnt for each individual substring 
    }
public:
    long long countSubstrings(string s, char c) {
        // return solve_brute(s, c);

        // return solve_better(s, c);

        // return solve_optimal_1(s, c);    

        return solve_optimal_2(s, c);       // Math
    }
};
