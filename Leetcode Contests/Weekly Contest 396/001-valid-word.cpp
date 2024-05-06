// https://leetcode.com/problems/valid-word/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char& ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_1(string& word) {
        int n = word.length();

        if (n < 3) return 0;

        int len = 0, cnt = 0;
        bool con = 1, vow = 1;
        for (char& c : word) {
            if (isVowel(c) && vow) len ++, vow = 0;
            // ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) => isalpha(c)
            else if (isalpha(c) && !isVowel(c) && con) {
                len ++, con = 0;
            }
            else if (c == '$' || c == '#' || c == '@') return 0;
        }
        return len >= 2;
    }

    // TC : O(N)
    // SC : O(1)
    bool better(string& word) {
        int n = word.length();

        if (n < 3) return 0;

        int len  = 0, cnt = 0;
        bool con = 0, vow = 0;

        for (char& c : word) {
            if (!isalpha(c) && !isdigit(c)) return 0; // '$', '#', '@'
            else if (isalpha(c)) {
                if(isVowel(c)) vow = 1;
                else con = 1;
            }
        }
        return con && vow;
    }
public:
    bool isValid(string word) {
        // return approach_1(word);

        return better(word);
    }
};