// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    // TC : O(N)
    // SC : O(1)
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int maxVowel = 0, maxConst = 0;
        for (char &ch : s) {
            freq[ch - 'a'] ++;
            if (isVowel(ch)) {
                maxVowel = max(maxVowel, freq[ch - 'a']);
            } else {
                maxConst = max(maxConst, freq[ch - 'a']);
            }
        }
        return (maxVowel + maxConst);
    }
};