// https://leetcode.com/contest/biweekly-contest-111/problems/make-string-a-subsequence-using-cyclic-increments/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(max(n, m))
    bool solve(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            int req  = s2[j] - 'a';
            int curr = s1[i] - 'a';

            if (curr == req || req == (curr + 1) % 26) j++;
            i++;
        }
        return j == m;
    }

    // TC = O(max(n, m))
    bool solve_optimal(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        int i = 0;
        int j = 0;
        
        for ( ; i<n && j<m; i++) {
            if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j]) 
                j++;
        }

        return j == m;
    }

public:
    bool canMakeSubsequence(string str1, string str2) {
        
        // return solve(str1, str2);

        return solve_optimal(str1, str2);
    }
};