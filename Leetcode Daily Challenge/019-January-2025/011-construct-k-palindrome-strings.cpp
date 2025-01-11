// https://leetcode.com/problems/construct-k-palindrome-strings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool approach_1(string& s, int k) {
        int n = s.length();
        if (n == k) return true;
        if (n  < k) return false;
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }  

        int oddFreq  = 0;
        for (int i = 0; i < 26; i ++) {
            if (freq[i] % 2) 
                oddFreq ++;
        }
        return oddFreq <= k;
    }
public:
    bool canConstruct(string s, int k) {
        return approach_1(s, k);
    }
};