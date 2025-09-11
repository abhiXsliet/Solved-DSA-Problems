// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/




class Solution {
    public int[] getNoZeroIntegers(int n) {
        // return approach_1(n);
        return approach_2(n);
    }

    // TC : O(log10(N))
    // SC : O(1)
    private static int[] approach_2(int n) {
        int a = n, b = 0, placeValue = 1;
        while (n > 1) {
            int take = (n % 10 == 1) ? 2 : 1;

            a -= (take * placeValue);
            b += (take * placeValue);

            n  = ((n - take) / 10);
            placeValue *= 10;
        }
        return new int[]{a, b};
    }

    // TC : O(N*log(N))
    // SC : O(1)
    private static int[] approach_1(int n) {
        for (int i = 1; i <= n; i ++) {
            int a = i;
            int b = n - i;
            if (noZero(a) && noZero(b)) {
                return new int[]{a, b};
            }
        }
        return new int[]{};
    }

    private static boolean noZero(int val) {
        while (val > 0) {
            if (val % 10 == 0) return false;
            val /= 10; 
        }
        return true;
    }
}