// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M*log(M) + N*log(N))
    // SC : O(1)
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size(), n = trainers.size();

        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int i = 0, j = 0, cntMatches = 0;
        while (i < m && j < n) {
            if (trainers[j] >= players[i]) {
                i ++, j ++;
                cntMatches += 1;
            } else {
                j ++;
            }
        }
        return cntMatches;
    }
};