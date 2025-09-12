// https://leetcode.com/problems/vowels-game-in-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char &ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    // TC : O(N)
    // SC : O(1)
    bool doesAliceWin(string s) {   
        int vowelsCnt = 0;
        for (char &ch : s) {
            if (isVowel(ch)) vowelsCnt += 1;
        }
        return vowelsCnt == 0 ? false : true;
    }
};