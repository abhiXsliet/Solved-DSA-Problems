// https://www.geeksforgeeks.org/problems/anagram-palindrome4720/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a'] ++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i ++) {
            if (freq[i] % 2) {
                cnt += 1;
            }
        }
        return cnt == 1 || cnt == 0;
    }
};