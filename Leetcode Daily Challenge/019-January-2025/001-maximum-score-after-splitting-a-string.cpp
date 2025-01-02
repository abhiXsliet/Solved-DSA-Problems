// https://leetcode.com/problems/maximum-score-after-splitting-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(string &s) {
        int n = s.length();
        int cntOnes = 0, cntZeros = 0;
        for (char &ch : s) {
            if (ch == '1') cntOnes ++;
        }

        int maxScore = INT_MIN;
        for (int i = 0; i < n - 1; i ++) {
            if (s[i] == '1') cntOnes --;
            else cntZeros ++;
            maxScore = max(maxScore, cntOnes + cntZeros);
        }
        return maxScore;
    }

    // TC : O(N)
    // SC : O(1)
    // Maximize (Left0 - Left1) for each index i, then add total1 at the end.
    int approach_2(string &s) {
        int n = s.length();
        int cntZeros = 0, cntOnes = 0;
        int maxScore = INT_MIN;
        for (int i = 0; i < n - 1; i ++) {
            if (s[i] == '0') cntZeros ++;
            else cntOnes  ++;
            maxScore = max(maxScore, cntZeros - cntOnes);
        }
        if (s[n - 1] == '1') cntOnes ++;
        return maxScore + cntOnes;
    }
public:
    int maxScore(string s) {
        // return approach_1(s);    // 2-Pass Soln.
        return approach_2(s);    // 1-Pass Soln.
    }
};