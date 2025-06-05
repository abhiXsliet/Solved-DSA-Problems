// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getOptimalIdx(string &word) {
        int n = word.size();
        int i = 0, j = 1;
        while (j < n) {
            int k = 0;
            while (j + k < n && word[i + k] == word[j + k]) k ++;

            if (j + k < n && word[i + k] < word[j + k]) {
                i = j;
                j ++;
            } else {
                j = j + k + 1;
            }
        }
        return i;
    }

    // TC : O(N^2)
    // SC : O(1)
    string approach_1(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;
        int len = (n - numFriends + 1);
        string result;
        for (int i = 0; i < n; i ++) {
            result = max(result, word.substr(i, len));
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    string approach_2(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;
        int len = (n - numFriends + 1); // max-possible len for lexiographically largest string
        
        // get the best suitable idx for lexiographically largest string
        int optimalIdx = getOptimalIdx(word); 

        int canTakeLen = min(len, n - optimalIdx);

        return word.substr(optimalIdx, canTakeLen);
    }
public:
    string answerString(string word, int numFriends) {
        // return approach_1(word, numFriends);
        return approach_2(word, numFriends);
    }
};