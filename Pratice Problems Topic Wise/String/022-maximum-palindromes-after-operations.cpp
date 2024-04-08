// https://leetcode.com/problems/maximum-palindromes-after-operations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*M)  Where M is the maximum length of string in words array
    // SC : O(N)    Where N is the size of words array
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> freq(26, 0);
        for (string& word : words) {
            for (char& ch : word) {
                freq[ch - 'a'] ++; 
            }
        }

        vector<int> str_len;
        for (string& word : words) {
            str_len.push_back(word.length());
        }

        sort(begin(str_len), end(str_len));

        // pairs cnt which is required
        int even = 0;
        // non-pairs cnt which is required
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            even += freq[i] / 2 ;
            odd  += (freq[i] % 2 != 0); // if (freq[i] % 2 == 0) odd ++;
        }

        int cntPalindrome = 0;
        for (int i = 0; i < str_len.size(); i++) {
            if (str_len[i] % 2 == 1) {
                if (odd) {
                    odd --;
                }
                else {
                    even --;    // gives 2 char even
                    odd ++;     // used 1 char for odd(non-pair) and left with 1 odd(non-pair) char
                }
            }
            if (even < str_len[i]/2) break; // half(char) + half(same as char) : create a pair
            even -= str_len[i]/2;
            cntPalindrome ++;
        }
        return cntPalindrome;
    }
};