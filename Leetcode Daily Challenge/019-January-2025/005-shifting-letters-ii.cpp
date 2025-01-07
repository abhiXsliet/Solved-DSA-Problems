// https://leetcode.com/problems/shifting-letters-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void shiftCharacters(string& s, int start, int end, int dirn) {
        for (int i = start; i <= end; i ++) {
            int val = s[i] - 'a';
            val = (dirn == 1 ? (val + 1) % 26 : (val - 1 + 26) % 26);
            s[i] = val + 'a';
        }
    }

    // TC : O(N * M)
    // SC : O(1)
    string approach_1(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        int m = shifts.size();
        for (int i = 0; i < m; i ++) {
            int start = shifts[i][0];
            int end   = shifts[i][1];
            int direc = shifts[i][2];

            shiftCharacters(s, start, end, direc);
        }
        return s;
    }

    // TC : O(N * M)
    // SC : O(1)
    string approach_2(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        int m = shifts.size();
        
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < m; i ++) {
            int start = shifts[i][0];
            int end   = shifts[i][1];
            int direc = shifts[i][2];
            prefix[start]   = direc == 1 ? prefix[start] + 1 : prefix[start] - 1;
            prefix[end + 1] = direc == 0 ? prefix[end+1] + 1 : prefix[end+1] - 1; 
        }
        for (int i = 1; i <= n; i ++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i ++) {
            int val = s[i] - 'a';
            val += (prefix[i] % 26);
            if (val < 0) {
                val = (val + 26);
            }
            s[i] = (val % 26) + 'a'; 
        }
        return s;
    }
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // return approach_1(s, shifts);   // brute : simulation

        return approach_2(s, shifts);   // calculate prefix +1/-1 for each shifts
    }
};