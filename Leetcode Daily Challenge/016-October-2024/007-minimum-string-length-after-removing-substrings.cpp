// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(string& s) {
        stack<char> stk;
        for (char& ch : s) {
            if (stk.empty()) {
                stk.push(ch);
                continue;
            } else {
                if ((stk.top() == 'A' && ch == 'B') || 
                    (stk.top() == 'C' && ch == 'D')) {

                    stk.pop();
                    continue;
                } else {
                    stk.push(ch);
                }
            } 
        }
        return stk.size();
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(string s) {
        string res;
        for (char& ch : s) {
            if (res.empty()) {
                res.push_back(ch);
            } else {
                if (ch == 'B' && res.back() == 'A' || ch == 'D' && res.back() == 'C') {
                    res.pop_back();
                } else {
                    res.push_back(ch);
                }
            }
        }
        return res.length();
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(string s) {
        int n = s.length();
        int i = 0;      // 'i' used for writting
        int j = i + 1;  // 'j' used for reading
        while (j < n) {
            if (i >= 0 && ((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D'))) {
                i --;
            } else {
                i ++;
                s[i] = s[j];
            }
            j ++;
        }
        return (i + 1);
    }
public:
    int minLength(string s) {
        // return approach_1(s);    // Using Stack

        // return approach_2(s);    // NO Stack

        return approach_3(s);    // NO Extra Space but modifying input   
    }
};