// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1




class Solution {
    public int minTime(int[] arr, int k) {
        int low  = Integer.MAX_VALUE;
        int high = 0;
        
        for (int num : arr) {
            low  = Math.min(low, num);
            high += num;
        }
        
        int ans = high;
        
        if (k == 1) return ans;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPaint(arr, k, mid)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    private static boolean canPaint(int[] arr, int k, int tar) {
        int painter = 0;
        int total = 0;
        for (int num : arr) {
            if (tar < num) return false;
            total += num;
            if (total == tar) {
                total = 0;
                painter += 1;
            } else if (total > tar) {
                total = num;
                painter += 1;
            }
        }
        if (total > 0) painter += 1;
        return painter <= k;
    }
}