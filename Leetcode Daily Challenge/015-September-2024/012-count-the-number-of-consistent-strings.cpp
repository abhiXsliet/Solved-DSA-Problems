// https://leetcode.com/problems/count-the-number-of-consistent-strings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M + N * K)
    // SC : O(26)
    int approach_1(string allowed, vector<string>& words) {
        vector<int> freq(26, 0);
        for (char& ch : allowed) {
            freq[ch - 'a'] ++;
        }

        int res = 0;
        for (string& str : words) {
            bool isConsistent = 1;
            for (auto& ch : str) {
                if (freq[ch - 'a'] == 0) {
                    isConsistent = 0;
                    break;
                }
            }
            // if (isConsistent) res ++;
            res += isConsistent;
        }
        return res;
    }
    
    // TC : O(M + N * K)
    // SC : O(1)
    int approach_2(string allowed, vector<string>& words) {
        int mask = 0;
        for (char& ch : allowed) {
            mask |= 1 << (ch - 'a');    // set the ith bit of mask
        }

        int res = 0;
        for (string& str : words) {
            bool isConsistent = 1;
            for (char& ch : str) {
                // check (ch - 'a') ith bit is set or not ??
                if ( !(mask & (1 << (ch - 'a'))) ) {
                    isConsistent = 0;
                    break;
                }
            }
            res += isConsistent;
        }
        return res;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // return approach_1(allowed, words);  // Freqency Array

        return approach_2(allowed, words);  // Bit Magic
    }
};