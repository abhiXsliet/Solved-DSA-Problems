// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(N)
    int brute(string s) {
        int n = s.length();
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i ++) {
            string substr;
            for (int j = i; j < n && s[i] == s[j]; j ++) {
                substr += s[j];
                mpp[substr] ++; // O(N) : at worst copying 'n' length string into map
            }
        }
        int substrLen = -1;
        for (auto it : mpp) {
            if (it.second >= 3) {
                int len = it.first.length();
                if (len > substrLen) {
                    substrLen = len;
                }
            }
        }
        return substrLen;
    }

    // TC : O(N^2 * log(N))
    // SC : O(N)
    int better(string s) {
        int n = s.length();
        map<pair<char,int>, int> mpp;
        for (int i = 0; i < n; i ++) {
            int len = 0;
            for (int j = i; j < n && s[i] == s[j]; j ++) {
                len ++;
                mpp[{s[i], len}] ++;    // log(N)
            }
        }
        int substrLen = -1;
        for (auto& it : mpp) {
            if (it.second >= 3) {
                substrLen = max(substrLen, it.first.second);
            }
        }
        return substrLen;
    }

    // TC : O(N)
    // SC : O(N)
    int optimal(string s) {
        int n = s.length();
        vector<vector<int>> freq(26, vector<int>(n + 1, 0));
       
        char prevChar = s[0];
        int length = 0;
        
        for (int i = 0; i < n; i ++) {
            char currChar = s[i];
            if (prevChar == currChar) {
                length += 1;
            } else {
                length = 1;
                prevChar = currChar;
            }
            freq[currChar - 'a'][length] += 1;
        }

        int substrLen = -1;
        for (int i = 0; i < 26; i ++) {
            int cummSum = 0;
            for (int j = n; j >= 1; j --) {
                cummSum += freq[i][j];
                if (cummSum >= 3) {
                    substrLen = max(substrLen, j);
                    break;
                }
            }
        }
        return substrLen;
    }
public:
    int maximumLength(string s) {
        // return brute(s);

        // return better(s);

        return optimal(s);
    }
};