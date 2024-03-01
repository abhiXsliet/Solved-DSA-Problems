// https://leetcode.com/problems/maximum-odd-binary-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    string solve_approach_1(string& s, int n) {
        int cntOne = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cntOne++;
        }
        
        if (cntOne == 0) return s;
        
        string str = "";
        for (int i = 0; i < n; i++) {
            str += '0';
        }
        
        if (cntOne >= 1) {
            str[n-1] = '1';
            cntOne --;
        }
        
        int i = 0;
        while(cntOne-- > 0 && i < n) {
            str[i++] = '1';
        }
        
        return str;
    }
public:
    string maximumOddBinaryNumber(string s) {
        return solve_approach_1(s, s.length());
    }
};