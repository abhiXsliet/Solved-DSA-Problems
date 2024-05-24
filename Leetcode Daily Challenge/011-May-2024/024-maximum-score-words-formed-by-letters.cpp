// https://leetcode.com/problems/maximum-score-words-formed-by-letters/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossibleToTake(string& s, unordered_map<char, int>& freq) {
        unordered_map<char, int> tempFreq = freq;
        for (int i = 0; i < s.length(); i++) {
            if (tempFreq[s[i]]-- <= 0) return false;
        }
        return true;
    }

    // TC : O(2^N * L)
    // SC : O(2^N)
    int solve(vector<string>& words, int idx, unordered_map<char, int>& freq, vector<int>& score) {
        if (idx == words.size()) return 0;

        int exclude = solve(words, idx + 1, freq, score);

        int include = 0;
        if (isPossibleToTake(words[idx], freq)) {
            int val = 0;
            for (int i = 0; i < words[idx].size(); i++) {
                char ch = words[idx][i];
                val += score[ch - 'a'];
                freq[ch]--;
            }
            include = val + solve(words, idx + 1, freq, score);
            for (char ch : words[idx]) freq[ch]++; // backtrack
        }

        return max(include, exclude);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> freq;
        for (char ch : letters) freq[ch]++;
        return solve(words, 0, freq, score);
    }
};