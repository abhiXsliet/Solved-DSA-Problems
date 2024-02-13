// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M) Where M = string length()
    // SC : O(1)
    bool checkPalindrome(string& s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i ++;
            j --;
        }
        return 1;
    }

    // TC : O(N * M) Where N = Words.size() & M = Individual string length
    // SC : O(1)
    string approach_1(vector<string>& words, int n) {
        for (string& str : words) {
            if (checkPalindrome(str)) {
                return str;
            }
        }
        return "";
    }

    // TC : O(N * M) Where N = Words.size()
    // SC : O(M)     Where M = Individual string length
    string approach_2(vector<string>& words, int n) {
        for (string& str : words) {
            string revStr = str;
            reverse(begin(revStr), end(revStr));

            if (str == revStr) 
                return str;
        }
        return "";
    }

    // TC : O(N * M) Where N = Words.size()
    // SC : O(M)     Where M = Individual string length
    string approach_3(vector<string>& words, int n) {
        for (string& word : words) {
            if ( word == string(rbegin(word), rend(word)) )
                return word;
        }
        return "";
    }

    // TC : O(N * M)
    // SC : O(1)
    string approach_4(vector<string>& words, int n) {
        for (string& word : words) {
            int len = word.length();
            if ( equal(begin(word), begin(word) + len/2, rbegin(word)) )
                return word;
        }
        return "";
    }
public:
    string firstPalindrome(vector<string>& words) {
        // return approach_1(words, words.size());

        // return approach_2(words, words.size());

        // return approach_3(words, words.size());

        return approach_4(words, words.size());
    }
};