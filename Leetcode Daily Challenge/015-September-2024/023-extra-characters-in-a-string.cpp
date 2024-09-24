// https://leetcode.com/problems/extra-characters-in-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int t[51];
    unordered_set<string> dict;

    // TC : O(N*N)
    // SC : O(N)
    int solve(string& s, int idx) {
        if (idx >= s.length()) return 0;

        if (t[idx] != -1) return t[idx];
        
        int ans = s.length();
        string str = "";
        
        for (int i = idx; i < s.length(); i ++) {
            str += s[i];
            int extra = 0;
            if (!dict.count(str)) { 
                extra = str.length();
            }
            ans = min(ans, extra + solve(s, i + 1));
        }
        
        return t[idx] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        for (string& s : dictionary) {
            dict.insert(s);
        }
        memset(t, -1, sizeof(t));
        return solve(s, 0);
    }
};