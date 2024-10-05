// https://leetcode.com/problems/permutation-in-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M + N) Where M = length of s1 & N = length of s2
    // SC : O(26)
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if (m > n) return false;

        vector<int> freqS1(26, 0);
        for (char& ch : s1) {
            freqS1[ch - 'a'] ++;
        }

        vector<int> freqS2(26, 0);
        int i = 0, j = 0;

        while (j < n) {
            freqS2[s2[j] - 'a'] ++;

            if (j - i + 1 == m) {
                if (freqS1 == freqS2)
                    return true;
                else {
                    freqS2[s2[i] - 'a'] --;
                    i ++;
                }
            }

            j ++;
        }

        return false;
    }
};