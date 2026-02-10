// https://www.geeksforgeeks.org/problems/koko-eating-bananas/1/




import java.util.*;

class Solution {
    public int kokoEat(int[] arr, int k) {
        int low = 0, high = Arrays.stream(arr).max().getAsInt();
        int ans  = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    private static boolean isPossible(int[] arr, int tar, int k) {
        if (tar == 0) return false;
        int cntHr = 0;
        for (int i = 0; i < arr.length; i ++) {
            cntHr += (arr[i] / tar);
            if (arr[i] % tar != 0) {
                cntHr ++;
            }
        }
        return (cntHr <= k);
    }
}
