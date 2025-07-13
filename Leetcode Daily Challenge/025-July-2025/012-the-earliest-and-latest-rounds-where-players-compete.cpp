// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N^2 * T(N/2))
    // SC : O(1)
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left  = firstPlayer;    
        int right = secondPlayer;

        if (left == (n - right + 1)) {
            return {1, 1};
        }

        if (left > (n - right + 1)) {
            int temp = (n - left + 1);
            left     = (n - right + 1);
            right    = temp;
        }

        int minRound = n, maxRound = 0;
        int nextRound = (n + 1) / 2;

        if (right <= nextRound) {   // case-1 : both best palyers are on the left side
            int cntLeft = left - 1;
            int cntMid  = right - left - 1;

            for (int survivorsLeft = 0; survivorsLeft <= cntLeft; survivorsLeft ++) {
                for (int survivorsMid = 0; survivorsMid <= cntMid; survivorsMid ++) {
                    
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + 1;

                    vector<int> tempRes = earliestAndLatest(nextRound, pos1, pos2);

                    minRound = min(minRound, tempRes[0] + 1);
                    maxRound = max(maxRound, tempRes[1] + 1);
                }
            }
        } else {    // case-2 : both best palyers on the different side (left & right end)
            int fightsRight = (n - right + 1);  // player which fights with the second best player
            int cntLeft     = (left - 1);
            int cntMid      = (fightsRight - left - 1);
            int remCntMid   = (right - fightsRight - 1);

            for (int survivorsLeft = 0; survivorsLeft <= cntLeft; survivorsLeft ++) {
                for (int survivorsMid = 0; survivorsMid <= cntMid; survivorsMid ++) {
                    
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + ((remCntMid + 1) / 2) + 1;

                    vector<int> tempRes = earliestAndLatest(nextRound, pos1, pos2);

                    minRound = min(minRound, tempRes[0] + 1);
                    maxRound = max(maxRound, tempRes[1] + 1);
                }
            }
        }

        return {minRound, maxRound};
    }
};