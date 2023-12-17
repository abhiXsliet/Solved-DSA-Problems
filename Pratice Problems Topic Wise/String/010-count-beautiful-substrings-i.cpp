// https://leetcode.com/problems/count-beautiful-substrings-i/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    // TC = O(N * N)
    // SC = O(1)
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int vowel_cnt = 0, cons_cnt = 0;
            for (int j = i; j < n; j++) {
                if (isVowel(s[j])) {
                    vowel_cnt ++;
                }
                else cons_cnt ++;

                if (vowel_cnt == cons_cnt && (vowel_cnt * cons_cnt) % k == 0) {
                    res ++;
                }
            }
        }
        return res;
    }
};