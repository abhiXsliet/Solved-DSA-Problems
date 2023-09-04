// https://leetcode.com/contest/biweekly-contest-112/problems/check-if-strings-can-be-made-equal-with-operations-i/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i = 0; i < 4; i++) {
            if ( s1[i] == s2[i]) continue;
            if (i + 2 < 4) {
                if (s1[i + 2] == s2[i]) {
                    swap(s1[i + 2], s1[i]);
                    continue; 
                }
            }
            return false;
        }
        return (s1==s2);
    }
};