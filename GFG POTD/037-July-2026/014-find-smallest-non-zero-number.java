// https://www.geeksforgeeks.org/problems/find-smallest-non-zero-number4510/1




class Solution {

    private boolean isPossible(long x, int[] arr) {
    
        final long LIMIT = Long.MAX_VALUE / 2;
    
        for (int val : arr) {
    
            if (x > LIMIT) {
                // Ab x itna bada hai ki future me kabhi negative nahi hoga.
                x = LIMIT;
            } else {
                x = 2L * x - val;
            }
    
            if (x < 0)
                return false;
        }
    
        return true;
    }

    public int find(int[] arr) {

        long low = 0;
        long high = 1_000_000_000L;
        long ans = high;

        while (low <= high) {

            long mid = low + (high - low) / 2;

            if (isPossible(mid, arr)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int) ans;
    }
}