// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int missingNumber(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i ++) {
            if (arr[i] > 0 && arr[i] <= n) {
                int idx  = arr[i] - 1;
                if (arr[i] != arr[idx]) {
                    int temp = arr[i];
                    arr[i]   = arr[idx];
                    arr[idx] = temp;
                    i --;
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            if (arr[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (n + 1);
    }
}
