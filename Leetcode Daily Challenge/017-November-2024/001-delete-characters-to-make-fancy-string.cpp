// https://leetcode.com/problems/delete-characters-to-make-fancy-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    string approach_1(string s) {
        int cnt = 1;
        for (int i = 1; i < s.length(); i ++) { // O(N)
            if (s[i] == s[i - 1]) cnt ++;
            else cnt = 1;
            
            if (cnt == 3) {
                s.erase(i, 1);  // O(N)
                i --;
                cnt --;
            }
        }
        return s;
    }

    // TC : O(N)
    // SC : O(N) 
    string approach_2(string s) {
        string res;
        for (char &ch : s) {
            if (res.empty() || res.size() < 2)
                res += ch;
            else {
                int n = res.size();
                if (res[n - 1] == res[n - 2] && res[n - 2] == ch) 
                    continue;
                else res += ch;
            } 
        }
        return res;
    }
public:
    string makeFancyString(string s) {
        // return approach_1(s);    // erase and modify in same string
        return approach_2(s);    // no change in input string   
    }
};