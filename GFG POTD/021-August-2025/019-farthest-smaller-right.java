// https://www.geeksforgeeks.org/problems/farthest-smaller-right/1




import java.util.*;

class Solution {
    // TC : O(N * log(N))
    // SC : O(N)
    public ArrayList<Integer> farMin(int[] arr) {
        int n = arr.length;
        int[] suffix = new int[n];
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i --) {
            suffix[i] = Math.min(suffix[i + 1], arr[i]);
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            result.add(getFarthestSmallestIdx(suffix, i + 1, n - 1, arr[i]));
        }
        return result;
    }
    // TC : O(log(N))
    // SC : O(1)
    private int getFarthestSmallestIdx(int[] suffix, int low, int high, int tar) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (suffix[mid] < tar) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}