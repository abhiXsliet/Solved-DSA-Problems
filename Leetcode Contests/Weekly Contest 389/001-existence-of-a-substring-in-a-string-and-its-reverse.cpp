// https://leetcode.com/contest/weekly-contest-389/problems/existence-of-a-substring-in-a-string-and-its-reverse/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N^2)
    bool isSubstringPresent(string s) {
        string rS = s;
        reverse(begin(rS), end(rS));
        
        int n = s.length();
        for (int i = 0; i < n-1; i++) {
            string substr = s.substr(i, 2);
            if (rS.find(substr) != string::npos)
                    return true;
        }
        return false;
    }
};