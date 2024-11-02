// https://leetcode.com/problems/circular-sentence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N) At worst
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if (sentence[0] != sentence[n - 1]) 
            return false;

        istringstream ss(sentence);
        string word;
        char prev = '$';

        while (getline(ss, word, ' ')) { // while (ss >> word) : this sytax can also be used
            int len = word.length();
            if (prev == '$') 
                prev = word[len - 1];
            else {
                if (prev != word[0])
                    return false;
                else 
                    prev = word[len - 1];
            }
        }

        return true;
    }
};