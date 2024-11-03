// https://leetcode.com/problems/rotate-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M)
    // SC : O(M)
    void getLPS(vector<int>& LPS, string s) {
        int m = s.length();

        for (int i = 1; i < m; i ++) {
            int j = LPS[i - 1]; // check till previous index is a prefix match

            while (j > 0 && s[i] != s[j]) { 
                j = LPS[j - 1];
            }

            if (s[i] == s[j]) j ++;
            LPS[i] = j;
        }
    }

    // TC : O(M^2)
    // SC : O(1)
    bool brute(string s, string goal) {
        int m = s.length(), n = goal.length();

        if (m != n) return false;

        for (int count = 1; count <= m; count ++) {
            if (s == goal) 
                return true;

            rotate(s.begin(), s.begin() + 1, s.end());
        }
        return false;
    }

    // TC : O(M*N) Where M = newS length & N = goal length
    // SC : O(M)
    bool better(string s, string goal) {
        if (goal.length() != s.length()) 
            return false;
        string newS = s + s;
        if (newS.find(goal) != string::npos) 
            return true;
        return false;
    }

    // TC : O(M + N)
    // SC : O(M)
    bool optimal(string s, string goal) {
        int m = s.length(), n = goal.length();
        if (m != n) return false;

        string newS = s + s;
        vector<int> LPS(newS.length(), 0);  // Default : LPS[0] = 0
        getLPS(LPS, newS);

        int i = 0, j = 0;
        while (i < newS.length()) {
            if (newS[i] == goal[j]) 
                i ++, j ++;
            else {
                if (j != 0) j = LPS[j - 1];
                else i ++;
            }
            if (j == n) return true;
        }
        return false;
    }
public:
    bool rotateString(string s, string goal) {
        // return brute(s, goal);     // shift one by one char and check
        // return better(s, goal);    // concatenate s + s
        return optimal(s, goal);   // KMP
    }
};