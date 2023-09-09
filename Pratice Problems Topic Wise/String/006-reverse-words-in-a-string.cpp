// https://leetcode.com/problems/reverse-words-in-a-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    string reverse(string & s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }

    // TC = O(N)
    // SC = O(N)
    string solve_brute(string& s) {
        int i = 0, j = s.length() - 1;
        string ans = "";
        for (; j >= i; j--) {
            ans += s[j];
        }

        i = 0;
        string result = "";
        for (; i < s.length(); i++) {
            if(ans[i] != ' ') {
                j = i;
                string str = "";
                while(ans[j] != ' ' && j < s.length()) {
                    str += ans[j];
                    j++;
                } 
                result += reverse(str) + ' ';
                i = j;
            }
        }

        if (!result.empty() && result[result.length()-1] == ' ') 
            result.erase(result.end()-1);

        return result;
    }
public:
    string reverseWords(string s) {

        return solve_brute(s);
    }
};