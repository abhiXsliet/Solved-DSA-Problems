// https://leetcode.com/problems/move-pieces-to-obtain-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : Exponential at worst due to exploring all possible swaps, memoized to remove redundant computations
    // SC : O(N^2) possible stated stored in map
    bool brute(string &s, string &t, unordered_map<string, bool>& mpp) {
        if (t == s) return true;

        if (mpp.count(s)) return mpp[s];

        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '_') continue;

            else if (i > 0 && s[i] == 'L' && s[i - 1] == '_') {
                swap(s[i], s[i - 1]);
                if (brute(s, t, mpp)) return true;
                swap(s[i], s[i - 1]); // Backtrack

            } else if (i < s.length() - 1 && s[i] == 'R' && s[i + 1] == '_') {
                swap(s[i], s[i + 1]);
                if (brute(s, t, mpp)) return true;
                swap(s[i], s[i + 1]);   // Backtrack
            }
        }

        return mpp[s] = false;
    }

    // TC : O(N)
    // SC : O(1)
    bool optimal(string &s, string &t) {
        int n = s.length();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && s[i] == '_') i ++;
            while (j < n && t[j] == '_') j ++;

            if (i == n || j == n) 
                return i == n && j == n;    // both string should be exhausted at the same time

            if (s[i] != t[j]) return false;
            
            if (s[i] == 'L' && j > i) return false;
            if (s[i] == 'R' && i > j) return false;
           
            i ++, j ++;
        }
        return true;
    }
public:
    bool canChange(string start, string target) {
        // unordered_map<string, bool> mpp;
        // return brute(start, target, mpp);    // Recursion + Memoization

        return optimal(start, target);
    }
};