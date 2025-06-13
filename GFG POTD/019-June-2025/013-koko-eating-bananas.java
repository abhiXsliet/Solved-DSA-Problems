// https://www.geeksforgeeks.org/problems/koko-eating-bananas/1




import java.util.*;

class Solution {
    // TC : O(N * log(max(arr))
    // SC : O(1)
    public int kokoEat(int[] arr, int k) {
        int n = arr.length;
        int low = 0, high = Arrays.stream(arr).max().getAsInt();
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, n, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    private boolean isPossible(int[] arr, int n, int tarVal, int k) {
        if (tarVal == 0) return false;
        int countHrs = 0;
        for (int i = 0; i < n; i ++) {
            countHrs += (arr[i] / tarVal);
            if (arr[i] % tarVal != 0) {
                countHrs ++;
            }
        }
        return countHrs <= k;
    }
}