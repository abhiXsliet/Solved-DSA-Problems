// https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int subarraySum(int[] arr) {
        int n = arr.length;
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            int val = ((n - i) * (i + 1));
            sum += (arr[i] * val);
        }
        return sum;
    }
}