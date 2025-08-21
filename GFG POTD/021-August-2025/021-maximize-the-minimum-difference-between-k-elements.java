// https://www.geeksforgeeks.org/problems/maximize-the-minimum-difference-between-k-elements/1




import java.util.*;

class Solution {
    // TC : O(N * log(N))
    // SC : O(1)
    public int maxMinDiff(int[] arr, int k) {
        Arrays.sort(arr);
        int low = 0, high = (arr[arr.length - 1] - arr[0]), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    // Greedily pick 'k' elements which is atleast >= tar + last picked element
    private boolean isPossible(int[] arr, int k, int tar) {
        int prev = arr[0], count = 1;
        for (int i = 1; i < arr.length; i ++) {
            if (arr[i] >= prev + tar) {
                count += 1;
                prev = arr[i];
            }
        }
        return count >= k;
    }
}