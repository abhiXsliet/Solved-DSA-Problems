// https://leetcode.com/problems/string-compression-iii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    string compressedString(string word) {
        string comp = "";

        int n = word.length();
        int i = 0;

        while (i < n) {
            int count = 0;
            char ch = word[i];

            while (i < n && count < 9 && word[i] == ch) {
                count++;
                i++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};