// https://leetcode.com/problems/power-of-two/




class Solution {
    public boolean isPowerOfTwo(int n) {
        // return approach_1(n);
        // return approach_2(n);
        // return approach_3(n);
        return approach_4(n);
    }

    // TC : O(1)
    private boolean approach_4(int n) {
        return (n > 0 && (n & (n - 1)) == 0);
    }

    // TC : O(1)
    private boolean approach_3(int n) {
        for (int i = 0; i <= 31; i ++) {
            if (Math.pow(2, i) == n) return true;
        }
        return false;
    }

    // TC : O(1)
    private boolean approach_2(int n) {
        long ans = 1;
        for (int i = 0; i <= 31; i ++) {
            if (ans == n) return true;
            ans *= 2;
        }
        return false;
    }

    // TC : O(log(N))
    private boolean approach_1(int n) {
        while (n > 0) {
            if (n == 0 || n == 1) return true;
            if (n % 2 == 0) n /= 2;
            else return false;
        }
        return false;
    }
}