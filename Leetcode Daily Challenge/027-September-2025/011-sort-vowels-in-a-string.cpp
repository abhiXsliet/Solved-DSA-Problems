// https://leetcode.com/problems/sort-vowels-in-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    // TC : O(N*log(N))
    // SC : O(N)
    string approach_1(string s) {
        string temp;
        for (char &ch : s) {
            if (isVowel(ch)) {
                temp += ch;
            }
        }

        auto cmp = [&](char a, char b) {
            return a < b;
        };
        sort(begin(temp), end(temp), cmp);

        int i = 0;
        string t;
        for (char &ch : s) {
            if (isVowel(ch)) {
                t += temp[i ++];
            } else {
                t += ch;
            }
        }
        return t;
    }

    // TC : O(N)
    // SC : O(1)
    string approach_2(string s) {
        unordered_map<char, int> mpp;
        for (char &ch : s) {
            if (isVowel(ch)) {
                mpp[ch] ++;
            }
        }

        string vowels = "AEIOUaeiou";
        int j = 0;

        for (char &ch : s) {
            if (isVowel(ch)) {
                while (mpp[vowels[j]] == 0) {
                    j ++;
                }
                ch = vowels[j];
                mpp[vowels[j]] --;
            }
        }

        return s;
    }
public:
    string sortVowels(string s) {
        // return approach_1(s);
        return approach_2(s);
    }
};