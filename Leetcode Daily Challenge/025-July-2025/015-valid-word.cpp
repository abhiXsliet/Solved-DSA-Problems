// https://leetcode.com/problems/valid-word/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(char &ch) {
        // return ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
        return isalpha(ch) || isdigit(ch);
    }
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    // TC : O(N)
    // SC : O(1)
    bool isValid(string word) {
        int n = word.length();
        if (n < 3) return false;
        bool vowel = 0, consonant = 0;
        for (char &ch : word) {
            ch = tolower(ch);
            if (!isValid(ch)) return false;
            else {
                if(isVowel(ch)) vowel = true;
                else if (!isdigit(ch)) consonant = true;
            }
        }
        return (vowel && consonant);
    }
};