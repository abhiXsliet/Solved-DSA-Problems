// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/




#include <bits/stdc++.h>   
using namespace std;

class Solution {
    unordered_set<string> getSubstringSizeK(string &s, int k) {
        unordered_set<string> st;
        int i = 0, j = 0;
        string str;
        while (j < s.length()) {
            str += s[j];
            if (j - i + 1 == k) {
                st.insert(str);
                str.erase(0, 1);
                i ++;
            }
            j ++;
        }
        return st;
    }
public:
    // TC : O(N * K)
    // SC : O(2^K * K)
    bool hasAllCodes(string s, int k) {
        unordered_set<string> substrings = getSubstringSizeK(s, k);
        return substrings.size() == pow(2, k);
    }
};