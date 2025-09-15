// https://leetcode.com/problems/maximum-number-of-words-you-can-type/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M + N)
    // SC : O(1)
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> brokenFreq(26, 0);
        for (char &ch : brokenLetters) {
            if (!brokenFreq[ch - 'a']) 
                brokenFreq[ch - 'a'] = 1;
        }

        istringstream ss(text);
        string word;
        int result = 0;

        while (getline(ss, word, ' ')) {
            bool canType = true;
            for (char &ch : word) {
                if (brokenFreq[ch - 'a']) {
                    canType = false;
                    break;
                }
            }
            if (canType) result += 1;
        }

        return result;
    }
};