// https://leetcode.com/problems/determine-if-two-strings-are-close/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) 
    // SC : O(26) ~= O(1) since map ends up storing all lowercase english alphabets
    bool solve_brute(string& word1, string& word2) {
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;

        for (char& ch : word1) mpp1[ch] ++;
        for (char& ch : word2) mpp2[ch] ++;

        // check if both the strings have same unique chars
        if (mpp1.size() != mpp2.size()) 
            return false;

        for (auto& it : mpp1) {
            if (mpp2.find(it.first) == mpp2.end())
                return false;
        }

        // check if both the strings have same freq distribution
        vector<int> freq1; // O(26)
        vector<int> freq2;

        for (auto& it : mpp1) {
            freq1.push_back(it.second);
        }

        for (auto& it : mpp2) {
            freq2.push_back(it.second);
        }

        // O(26*log(26))
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        return freq1 == freq2;
    }

    // TC : O(N) 
    // SC : O(26) ~= O(1) since map ends up storing all lowercase english alphabets
    bool solve_optimal(string& word1, string& word2) {
        int m = word1.length();
        int n = word2.length();

        // If the lengths are not equal, the words cannot be close strings
        if (n != m) return false;

        vector<int> freq1(26); 
        vector<int> freq2(26);

        for (char& ch : word1) freq1[ch - 'a'] ++;
        for (char& ch : word2) freq2[ch - 'a'] ++;

        // Check if both words have the same set of unique characters
        for (int i = 0; i < 26; i++) {
            // If a char is present in both words, continue to next char
            if (freq1[i] != 0 && freq2[i] != 0) continue;
            // If a char is absent in both words, continue to next char
            if (freq2[i] == 0 && freq2[i] == 0) continue;

            // If a char is present in word-1 but not in other
            return false;
        }

        // O(26*log(26))
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        // If the sorted frequency arrays are equal, the words are close strings
        return freq1 == freq2;
    }
public:
    bool closeStrings(string word1, string word2) {
        // return solve_brute(word1, word2);

        return solve_optimal(word1, word2);
    }
};