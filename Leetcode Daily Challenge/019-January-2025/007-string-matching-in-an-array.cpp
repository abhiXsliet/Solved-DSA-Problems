// https://leetcode.com/problems/string-matching-in-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(m)
    // SC : O(m)
    vector<int> get_lps(string& pattern, int m) {
        vector<int> LPS(m, 0);
        for (int i = 1; i < m; i ++) {
            int j = LPS[i - 1];
            while (j > 0 && pattern[i] != pattern[j])
                j = LPS[j - 1];
            if (pattern[i] == pattern[j]) j ++;
            LPS[i] = j;
        }
        return LPS;
    }

    // TC : O(m1 + m2)
    // SC : O(m1)
    bool KMP(string& pattern, string& text) {
        int m1 = text.length(), m2 = pattern.length();
        vector<int> LPS = get_lps(pattern, m2);

        int i = 0, j = 0;
        while (i < m1) {
            if (text[i] == pattern[j]) {
                i ++, j ++;
            } else {
                if (j > 0) j = LPS[j - 1];
                else i ++;
            }
            if (j == m2) return true;
        }
        return false;
    }

    // TC : O(N * N * M)
    // SC : O(1)
    vector<string> approach_1(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                   result.push_back(words[i]);
                   break;
                }
            }
        }
        return result;
    }

    // TC : O(N*N*M)
    // SC : O(M)
    vector<string> approach_2(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == j) continue;
                if (KMP(words[i], words[j])) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        return approach_1(words);    // BRUTE

        // return approach_2(words);    // KMP 

        // return approach_3(words);    // TRIE : Pending??
    }
};