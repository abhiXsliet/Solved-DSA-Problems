// https://leetcode.com/problems/count-the-number-of-special-characters-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    int brute(string& word) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        for (char& ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                st1.insert(ch - 'a');
            }
            else {
                st2.insert(ch - 'A');
            }
        }
        int ans = 0;
        for (int num : st1) {
            if (st2.find(num) != st2.end()) {
                ans += 1;
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal_1(string& word) {
        vector<int> lower(26, 0), upper(26, 0);
        for (char c : word) {
            if (islower(c)) lower[c - 'a']++;
            else upper[c - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] > 0 && upper[i] > 0) ans++;
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal_2(string& word) {
                vector<int> lower(26, -1), upper(26, -1);

        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i])) {
                lower[word[i] - 'a'] = i;
            }
            else {
                upper[word[i] - 'A'] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] != -1 && upper[i] != -1) {
                ans += 1;
            }
        }
        return ans;
    }
public:
    int numberOfSpecialChars(string word) {
        // return brute(word);

        // return optimal_1(word);  // Used Freq of Char

        return optimal_2(word);  // Used Indices of char
    }
};