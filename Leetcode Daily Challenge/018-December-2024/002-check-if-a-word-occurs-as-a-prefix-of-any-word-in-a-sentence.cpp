// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N)
    // SC : O(M)
    int approach_1(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int pos = 1;
        while (ss >> word) {
            int m = word.length(), n = searchWord.length();
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (word[i] == searchWord[j]) {
                    i ++, j ++;
                } else break;
            }
            if (j == n) return pos;
            pos ++;
        }
        return -1;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        return approach_1(sentence, searchWord);
                                                    // Trie : Pending??
    }
};