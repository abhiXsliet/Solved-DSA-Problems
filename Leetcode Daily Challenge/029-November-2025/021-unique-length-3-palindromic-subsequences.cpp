// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(26 * N) 
    // SC : O(N) At worst there are only 26 lowercase possible
    int approach_1(string &s) {
        int n = s.length();
        unordered_map<char, pair<int, int>> mpp;    // it stores the first and last occurances of each character
        for (int i = 0; i < n; i ++) {
            if (mpp.count(s[i])) {
                mpp[s[i]].second = i;
            } else {
                mpp[s[i]].first  = i;
                mpp[s[i]].second = i;
            }
        }
        int ans = 0;
        for (auto& it : mpp) { // O(26)
            int start = it.second.first;
            int end   = it.second.second;
            unordered_set<char> st;
            for (int i = start + 1; i < end; i ++) {    // ~O(N) : potentially processing entire string multiple times
                st.insert(s[i]);
            }
            ans += st.size();
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(N) At Worst, only 26 lowercase characters are inserted in map
    int approach_2(string &s) {
        int n = s.length();
        unordered_map<char, pair<int, int>> mpp;    // it stores the first and last occurances of each character
        for (int i = 0; i < n; i ++) {
            if (mpp.count(s[i])) {
                mpp[s[i]].second = i;
            } else {
                mpp[s[i]].first  = i;
                mpp[s[i]].second = i;
            }
        }
        
        // freq[c][i] stores the frequency of character 'c' in the prefix up to index 'i'
        vector<vector<int>> freq(26, vector<int>(n, 0));  
        for (int i = 0; i < n; i ++) {
            int c = s[i] - 'a';
            freq[c][i] ++;
        }  

        for (int c = 0; c < 26; c ++) {
            for (int i = 1; i < n; i ++) {
                freq[c][i] += freq[c][i - 1];
            }
        }

        int ans = 0;
        for (auto& it : mpp) { // O(26)
            int idx   = it.first - 'a';
            int start = it.second.first;
            int end   = it.second.second;
            for (int c = 0; c < 26; c ++) {
                if (start == end) continue;
                int val = (freq[c][end - 1] - freq[c][start]);
                if (val) ans += 1;
            }
        }
        return ans;
    }
public:
    int countPalindromicSubsequence(string s) {
        // return approach_1(s);   // BRUTE
        return approach_2(s);   // Optimal : freq[c][i] freq. of char c at index i
    }
};