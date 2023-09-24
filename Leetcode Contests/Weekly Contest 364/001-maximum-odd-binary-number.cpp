// https://leetcode.com/contest/weekly-contest-364/problems/maximum-odd-binary-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
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
        
        // cout << cntOne << endl;
        
        int i = 0;
        while(cntOne-- > 0 && i < n) {
            str[i++] = '1';
        }
        
        return str;
    }
};