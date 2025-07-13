// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/




import java.util.*;

class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        int m = players.length, n = trainers.length;

        Arrays.sort(players);
        Arrays.sort(trainers);

        int i = 0, j = 0, cntMatches = 0;
        while (i < m && j < n) {
            if (trainers[j] >= players[i]) {
                i ++;
                j ++;
                cntMatches += 1;
            } else {
                j ++;
            }
        }
        return cntMatches;
    }
}