// https://leetcode.com/problems/furthest-point-from-origin/




class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int cntL = 0, cntR = 0, cntDash = 0;
        for (char ch : moves.toCharArray()) {
            if (ch == 'L') cntL += 1;
            else if (ch == 'R') cntR += 1;
            else cntDash += 1;
        }
        return Math.abs(cntL - cntR) + cntDash;
    }
}