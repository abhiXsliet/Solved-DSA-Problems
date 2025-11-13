// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxOperations(string s) {
        int n          = s.length();
        int result     = 0;
        int i          = 0;
        int count1seen = 0;

        while(i < n) {
            if(s[i] == '0') {
                result += count1seen;
                while(i < n && s[i] == '0') //moved till first '0' occurence
                    i++;
            } else {
                count1seen++;
                i++;
            }
        }

        return result;
    }
};