// https://leetcode.com/problems/excel-sheet-column-title/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // TC = O( log(n) ) -> log base 26 of n
    // SC = O( 1 )
    string convertToTitle(int columnNumber) {
        string str = "";
        int rem = 0;
        
        while(columnNumber > 0) {
            rem = (columnNumber - 1) % 26;
            
            char ch = 'A' + rem;
            str += ch;

            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};