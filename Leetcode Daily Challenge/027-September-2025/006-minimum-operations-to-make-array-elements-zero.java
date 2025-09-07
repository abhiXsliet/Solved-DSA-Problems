// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/




class Solution {
    // TC : O(Q * log4(max(qr)))
    // SC : O(1)
    public long minOperations(int[][] queries) {
        long result = 0;
        for (int[] query : queries) {
            long l = query[0], r = query[1];

            long steps = getSteps(l, r);

            result += (steps + 1) / 2;
        }
        return result;
    }

    private static long getSteps(long l, long r) {
        long L = 1, steps = 1, stepsToReachZero = 0;

        while (r >= L) {
            long R = L * 4 - 1;

            long start = Math.max(L, l);
            long end   = Math.min(R, r);

            if (start <= end) {
                stepsToReachZero += ((end - start + 1) * steps);
            }

            L     *= 4;
            steps += 1;
        }

        return stepsToReachZero;
    }
}