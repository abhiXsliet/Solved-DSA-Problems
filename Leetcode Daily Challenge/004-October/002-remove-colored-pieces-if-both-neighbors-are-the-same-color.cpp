// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();

        int alice = 0;
        int bob   = 0;

        for (int i = 1; i < n - 1; i++) {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A')
                    alice++;
                else 
                    bob++;
            }
        }

        return alice > bob;
    }
};