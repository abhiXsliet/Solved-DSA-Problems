// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1




class Solution {
    // TC : O(N * log(sum(arr)))
    // SC : O(1)
    public int findPages(int[] arr, int k) {
        int n = arr.length;
        
        if (k > n) return -1;
        
        int low = Integer.MIN_VALUE, high = 0;
        for (int val : arr) {
            low  = Math.max(low, val);
            high += val;
        }
        
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
    
    private boolean isPossible(int[] arr, int k, int tar) {
        int sumPages = 0, students = 1;
        for (int page : arr) {
            if (page > tar) return false;
            if (sumPages + page <= tar) {
                sumPages += page;
            } else {
                students += 1;
                if (students > k) return false;
                sumPages = page;
            }
        }
        return students <= k;
    }
}