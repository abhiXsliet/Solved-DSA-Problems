// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/




class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        for (int i = 1; i <= n / 2; i ++) {
            result[i - 1] = i;
            result[n - i] = -i;
        }
        return result;
    }
}