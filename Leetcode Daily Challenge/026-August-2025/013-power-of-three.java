// https://leetcode.com/problems/power-of-three/




class Solution {
    public boolean isPowerOfThree(int n) {
        // return approach_1(n);
        // return approach_2(n);
        return approach_3(n);
    }

    // TC : O(1)
    // SC : O(1)
    private boolean approach_3(int n) {
        final int MAX_POW3 = 1162261467;    // 3^19
        return ((n > 0) && MAX_POW3 % n == 0);
    }

    // TC : O(log3(n))
    // SC : O(1)
    private boolean approach_2(int n) {
        if (n < 1) return false;

        double logBase3 = Math.log(n) / Math.log(3);

        int exponent    = (int) Math.round(logBase3);

        long ans = 1;
        for (int i = 0; i < exponent; i ++) ans *= 3;

        return ans == n;
    }

    // TC : O(log3(n))
    // SC : O(1)
    private boolean approach_1(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
}