// https://leetcode.com/problems/count-vowel-strings-in-ranges/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool isVowelWord(string& word) {
        int m = word.length();
        return isVowel(word[0]) && isVowel(word[m - 1]);
    }
public:
    // TC : O(N + Q)
    // SC : O(N)
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), q = queries.size();
        
        vector<int> store(n, 0);
        store[0] = isVowelWord(words[0]) == 1 ? 1 : 0;
        for (int i = 1; i < n; i ++) {
            store[i] = (isVowelWord(words[i]) == 1) ? 1 + store[i - 1] : store[i - 1];
        }

        vector<int> result(q, 0);
        for (int i = 0; i < q; i ++) {
            int lQ = queries[i][0], rQ = queries[i][1];
            result[i] = (lQ > 0) ? store[rQ] - store[lQ - 1] : store[rQ];
        }
        return result;
    }
};