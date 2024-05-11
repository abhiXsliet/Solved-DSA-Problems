// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    int solve_brute(string& s) {
        int n = s.length();
        s = s + s;
        string s1, s2;
        bool flag = 1;
        
        for (int i = 0; i < 2*n; i++) {
            if (flag) {
                s2 += '1';
                s1 += '0';
            }
            else {
                s2 += '0';
                s1 += '1';
            }
            flag = !flag;
        }

        int cntFlips = INT_MAX;
        for (int i = 0; i < n; i++) {
            int diff_1 = 0, diff_2 = 0;
            for (int j = i; j < n + i; j++) {
                if (s[j] != s1[j]) diff_1 ++;
                if (s[j] != s2[j]) diff_2 ++;
            }
            cntFlips = min(cntFlips, min(diff_1, diff_2));
        }

        return cntFlips;
    }

    // TC : O(N)
    // SC : O(N)
    int solve_optimal(string& s) {
        int n = s.length();
        s = s + s;
        string s1, s2;

        for (int i = 0; i < 2*n; i++) {
            s1 += i % 2 == 0 ? '0' : '1';
            s2 += i % 2 == 0 ? '1' : '0';
        }
        
        int cntFlips = INT_MAX;
        int diff_1 = 0, diff_2 = 0;
        int i = 0, j = 0;
        
        while (j < 2*n) {
            if (s[j] != s1[j]) diff_1 ++;
            if (s[j] != s2[j]) diff_2 ++;

            if (j - i + 1 == n) {   // window of size 'N'
                cntFlips = min(cntFlips, min(diff_1, diff_2));
                if (s[i] != s1[i]) diff_1 --;
                if (s[i] != s2[i]) diff_2 --;
                i ++;
            }

            j ++;
        }

        return cntFlips;
    }
public:
    int minFlips(string s) {
        // return solve_brute(s);

        return solve_optimal(s);
    }
};