// https://leetcode.com/contest/weekly-contest-359/problems/check-if-a-string-is-an-acronym-of-words/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        string str = "";
        for(int i = 0; i < n; i++) {
            str += words[i][0];
        }
        
        if(str == s) return 1;
        else return 0;
    }
};