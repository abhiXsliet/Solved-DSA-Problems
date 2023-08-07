// https://leetcode.com/contest/weekly-contest-357/problems/faulty-keyboard/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    string reverse(string& s) {
        int n = s.length();
        int id1 = 0;
        int id2 = n - 1;
        while(id1 < id2) {
            swap(s[id1], s[id2]);
            id1++;
            id2--;
        }
        return s;
    }
public:
    string finalString(string s) {
        int n = s.length();
        int cnt = 0;
        string temp;
        for(int i = 0; i < n; i ++) {
            if(s[i] == 'i') {
                reverse(temp);   
            } else {
                temp += s[i];
            }
        }
        return temp;
    }
};