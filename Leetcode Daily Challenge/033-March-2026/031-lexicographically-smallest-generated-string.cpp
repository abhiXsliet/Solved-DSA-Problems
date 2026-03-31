// https://leetcode.com/problems/lexicographically-smallest-generated-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSameFromI(string word, string s2, int i, int m) {
        int j_ = 0;
        for (int j = i; j <= i + m - 1; j ++) {
            if (word[j] != s2[j_ ++]) return false;
        }
        return true;
    }
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        int N = n + m - 1;
        string word = string(N, '#');

        vector<bool> canChange(N, 0);

        for (int i = 0; i < n; i ++) {
            if (str1[i] == 'T') {
                int i_ = i;
                for (int j = 0; j < m; j ++) {
                    if (word[i_] != '#' && word[i_] != str2[j])
                        return "";
                        
                    word[i_ ++] = str2[j];   
                }
            }
        }

        for (int i = 0; i < N; i ++) {
            if (word[i] == '#') {
                word[i] = 'a';
                canChange[i] = 1;
            }
        }

        for (int i = 0; i < n; i ++) {
            if (str1[i] == 'F') {
                // check equals, starting from 'i' to len 'm' in word
                if (isSameFromI(word, str2, i, m)) {
                    bool changed = false;
                    for (int j = i + m - 1; j >= i; j --) {
                        if (canChange[j]) {
                            word[j] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if (!changed) return "";
                }
            }
        }
        return word;
    }
};