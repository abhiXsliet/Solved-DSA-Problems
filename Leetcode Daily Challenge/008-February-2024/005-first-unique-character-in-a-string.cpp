// https://leetcode.com/problems/first-unique-character-in-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(string& s, int n) {
        unordered_map<int, int> mpp;
        for (char& ch : s) mpp[ch] ++;
        for (int i = 0; i < s.length(); i++) {
            if (mpp[s[i]] == 1) return i;
        }
        return -1;
    }

    // TC : O(N)
    // SC : O(26) ~= O(1)
    int solve_approach_2(string& s, int n) {
        vector<pair<int, int>> freq(26, {0, -1}); // {count of chars, idx of char}

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            freq[idx].first ++;
            freq[idx].second = i;
        }
        
        int minIdx = INT_MAX;
        for (auto& it : freq) {
            if (it.first == 1 && it.second < minIdx)
                minIdx = it.second;
        }

        return minIdx == INT_MAX ? -1 : minIdx;
    }
public:
    int firstUniqChar(string s) {
        // return solve_approach_1(s, s.length());

        return solve_approach_2(s, s.length());
    }
};