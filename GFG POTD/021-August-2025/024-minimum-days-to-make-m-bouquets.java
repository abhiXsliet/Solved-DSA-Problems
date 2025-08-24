// https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1




import java.util.*;

class Solution {
    // TC : O(N * log(maxi - mini))
    // SC : O(1)
    public int minDaysBloom(int[] arr, int k, int m) {
        int low  = Arrays.stream(arr).min().getAsInt();
        int high = Arrays.stream(arr).max().getAsInt();
        int ans  = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, m, mid)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
    
    // Is it possible to make 'm' bouquets in 'tar' days where making a bouquet will cost 'k' consecutive bloomed flowers
    private boolean isPossible(int[] arr, int k, int m, int tar) {
        int bouquets = 0, consec = 0;
        for (int days : arr) {
            if (days > tar) {
                consec = 0;
            } else {
                consec += 1;
                if (consec == k) {
                    consec = 0;
                    bouquets += 1;
                }
            }
        }
        return bouquets >= m;
    }
}