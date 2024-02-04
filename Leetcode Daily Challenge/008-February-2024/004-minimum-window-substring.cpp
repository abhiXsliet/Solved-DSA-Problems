// https://leetcode.com/problems/minimum-window-substring/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = s.length()
    // SC : O(M) Where M = t.length()
    string solve_optimal_1(string& s, string& t) {
        int n = s.length();

        unordered_map<char, int> mpp;
        for (char& ch : t) mpp[ch] ++;

        int startIdx = -1;
        int count = mpp.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;

        while (j < n) {
            
            if (mpp.find(s[j]) != mpp.end()) {
                mpp[s[j]] --;

                if (mpp[s[j]] == 0) count --;
            }

            while (count == 0) {
                if (mpp.find(s[i]) != mpp.end()) {
                    mpp[s[i]] ++;

                    if (mpp[s[i]] > 0) 
                        count ++;
                }
                // Before incrementing 'i' check the minLen and update it
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                i++;
            }
            j ++;
        }

        if (minLen == INT_MAX) return "";
        return s.substr(startIdx, minLen);
    }

    // TC : O(N)
    // SC : O(N)
    string solve_optimal_2(string& s, string& t) {
        unordered_map<char, int> mpp;
        
        for (char& ch : t) mpp[ch] ++;

        int startIdx = -1;
        int minLen   = INT_MAX;
        int countReq = t.length();
        int i = 0, j = 0;

        while (j < s.length()) {
            if (mpp[s[j]] > 0) {
                countReq --; // took one char which is needed
            }

            mpp[s[j]] --; // always 

            while (countReq == 0) {
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    startIdx = i;
                }

                mpp[s[i]] ++;

                if (mpp[s[i]] > 0) 
                    countReq ++;
                
                i++;
            }

            j ++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
public:
    string minWindow(string s, string t) {
        // return solve_optimal_1(s, t);

        return solve_optimal_2(s, t);
    }
};