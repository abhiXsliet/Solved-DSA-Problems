// https://leetcode.com/problems/longest-palindrome/



#include <bits/stdc++.h>   
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for (char& ch : s) {
            freq[ch] ++;
        }

        int len = 0;
        for (auto& it : freq) {
            if (it.second % 2 == 0) {
                len += it.second;
                it.second = 0;
            } else {
                len += it.second - 1;
                it.second -= (it.second - 1);
            }
        }

        for (auto& it : freq) {
            if (it.second % 2 == 1) {
                len += 1;
                break;
            }
        }
        
        return len;
    }
};