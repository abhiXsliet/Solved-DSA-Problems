// https://leetcode.com/problems/power-of-four/




class Solution {
    public boolean isPowerOfFour(int n) {
        // return approach_1(n);
        // return approach_2(n);
        return approach_3(n);
    }

    // TC : O(1)
    // SC : O(1)
    private boolean approach_3(int n) {
        return (n > 0 && (n & (n - 1)) == 0 && ((n - 1) % 3 == 0));
    }

    // TC : O(log(N))
    // SC : O(1)
    private boolean approach_2(int n) {
        double logBase4 = Math.log(n) / Math.log(4);
        int exponent    = (int) Math.round(logBase4);

        long ans = 1;
        for (int i = 0; i < exponent; i ++) ans *= 4;

        return ans == n;
    }

    // TC : O(log(N))
    // SC : O(1)
    private boolean approach_1(int n) {
        if (n < 1) return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
}