// https://leetcode.com/problems/bag-of-tokens/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N * log(N))
    // SC : O(1)
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n        = tokens.size();
        int i        = 0;
        int j        = n - 1;
        int score    = 0;
        int maxScore = 0;

        sort(begin(tokens), end(tokens));

        while (i <= j) {
            if (tokens[i] <= power) {
                score += 1;
                power -= tokens[i];
                i ++;
            }
            else if (score > 0 && tokens[j] >= 1){
                power += tokens[j];
                score -= 1;
                j --;
            }
            else break; // No more tokens can be used to increase the score
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};