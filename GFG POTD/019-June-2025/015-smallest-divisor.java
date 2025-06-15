// https://www.geeksforgeeks.org/problems/smallest-divisor/1




import java.util.*;

class Solution {
    // TC : O(N * maxi(arr[i]))
    // SC : O(1)
    int smallestDivisor(int[] arr, int k) {
        int n = arr.length;
        int low = 1, high = Arrays.stream(arr).max().getAsInt();
        int ans = Integer.MAX_VALUE;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getSummationDiv(arr, n, mid) <= k) {
                ans  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }
    private int getSummationDiv(int[] arr, int n, int div) {
        int countSum = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] % div != 0) countSum += 1;
            countSum += (arr[i] / div);
        }
        return countSum;
    }
}