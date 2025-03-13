// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // TC : O(N)
    // SC : O(1)
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<int, int> mpp;    // a, b, c
        int i = 0, j = 0, cntSubstr = 0;
        while (j < n) {
            mpp[s[j]] ++;
            while (mpp.size() == 3) {
                cntSubstr += (n - j);
                mpp[s[i]] --;
                if (mpp[s[i]] == 0) mpp.erase(s[i]);
                i ++;
            }
            j ++;
        }
        return cntSubstr;
    }
};