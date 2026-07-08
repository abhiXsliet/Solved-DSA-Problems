// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/




class Solution {
    private final int M = 1_000_000_007;

    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();

        int[] nonZeroDigitCnt = new int[n];
        long[] nonZeroDigitNum = new long[n];
        long[] nonZeroDigitSum = new long[n];
        long[] pow10 = new long[n + 1];

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        nonZeroDigitCnt[0] = (s.charAt(0) - '0' == 0) ? 0 : 1;
        for (int i = 1; i < n; i++) {
            int digit = s.charAt(i) - '0';
            nonZeroDigitCnt[i] = nonZeroDigitCnt[i - 1] + (digit != 0 ? 1 : 0);
        }

        nonZeroDigitNum[0] = s.charAt(0) - '0';
        for (int i = 1; i < n; i++) {
            int digit = s.charAt(i) - '0';
            if (digit != 0) {
                nonZeroDigitNum[i] = (nonZeroDigitNum[i - 1] * 10 + digit) % M;
            } else {
                nonZeroDigitNum[i] = nonZeroDigitNum[i - 1];
            }
        }

        nonZeroDigitSum[0] = s.charAt(0) - '0';
        for (int i = 1; i < n; i++) {
            nonZeroDigitSum[i] = nonZeroDigitSum[i - 1] + (s.charAt(i) - '0');
        }

        int q = queries.length;
        int[] result = new int[q];

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long sum = nonZeroDigitSum[r] - ((l == 0) ? 0 : nonZeroDigitSum[l - 1]);

            long prevNum = (l == 0) ? 0 : nonZeroDigitNum[l - 1];

            int k = nonZeroDigitCnt[r] - ((l == 0) ? 0 : nonZeroDigitCnt[l - 1]);

            if (k == 0) {
                result[i] = 0;
                continue;
            }

            long x = (nonZeroDigitNum[r] - (prevNum * pow10[k]) % M + M) % M;

            result[i] = (int) ((x * sum) % M);
        }

        return result;
    }
}