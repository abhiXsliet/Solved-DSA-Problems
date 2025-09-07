// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/




class Solution {
    // TC : O(1)
    // SC : O(1)
    public int makeTheIntegerZero(int num1, int num2) {
        int t = 0;

        while (true) {
            long val = (long)num1 - (long)t * num2;

            if (val < 0) return -1;

            if (Long.bitCount(val) <= t && t <= val) {
                return t;
            }

            t += 1;
        }

        // code flow unreachable here
    }
}