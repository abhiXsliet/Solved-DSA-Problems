// https://leetcode.com/problems/find-special-substring-of-length-k/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkIfNextPrevCharSame(string s, int n, int i, int j) {
        if ( ((i - 1 >= 0) && (s[i] == s[i - 1])) || ((j + 1 < n) && (s[j] == s[j + 1])) ) {
            return false;
        }
        return true;
    }
public:
    // TC : O(N)
    // SC : O(K)
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mpp;
        int i = 0, j = i;
        while (j < n) {
            mpp[s[j]] ++;
            if (j - i + 1 == k) {
                if (mpp.size() == 1) {
                    if (checkIfNextPrevCharSame(s, n, i, j))
                        return true;
                }
                mpp[s[i]] --;
                if (mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i ++;
            }
            j ++;
        }
        return false;
    }
};