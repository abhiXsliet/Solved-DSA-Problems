// https://www.geeksforgeeks.org/problems/remove-spaces0128/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    string approach_1(string &s) {
        string result;
        for (char &ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result += ch;
            }
        }
        return result;
    }
    
    string approach_2(string &s) {
        int n = s.length();
        int i = 0, j = 0;   // i -> write & j -> read ptr 
        while (j < n) {
            if (s[j] != ' ') {
                s[i] = s[j];
                i ++;
            }
            j ++;
        }
        s.resize(i);
        return s;
    }
  public:
    string removeSpaces(string& s) {
        // return approach_1(s);
        return approach_2(s);
    }
};