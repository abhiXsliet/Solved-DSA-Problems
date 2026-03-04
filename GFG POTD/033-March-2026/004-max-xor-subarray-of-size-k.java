// https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1/




class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        int n = arr.length;
        int i = 0, j = 0;
        int xored = 0, maxXor = 0;
        while (j < n) {
            xored ^= arr[j];
            if (j - i + 1 == k) {
                maxXor = Math.max(maxXor, xored);
                xored ^= arr[i];
                i ++;
            }
            j ++;
        }
        return maxXor;
    }
}