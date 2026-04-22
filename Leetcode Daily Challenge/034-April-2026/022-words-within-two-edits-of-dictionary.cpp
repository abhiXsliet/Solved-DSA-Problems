// https://leetcode.com/problems/words-within-two-edits-of-dictionary/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getMissMatchCnt(string &a, string &b) {
        int cntMissMatch = 0;
        int i = 0, j = 0;
        while (i < a.size() || i < b.size()) {
            if (a[i] != b[j]) {
                cntMissMatch += 1;
            }
            i ++, j ++;
        }
        return cntMissMatch;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int q = queries.size();
        int m = dictionary.size();

        vector<string> result;
        for (int i = 0; i < q; i ++) {
            for (int j = 0; j < m; j ++) {
                int missMatchCnt = getMissMatchCnt(queries[i], dictionary[j]);
                if (missMatchCnt <= 2) {
                    result.push_back(queries[i]);
                    break;
                }
            }
        }
        return result;
    }
};