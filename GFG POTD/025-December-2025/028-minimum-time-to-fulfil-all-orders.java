// https://www.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1/




class Solution {
    // TC : O(m * √T * log T)
    // SC : O(1)
    public int minTime(int[] ranks, int n) {
        int low = 1, high = 1000000000;
        int ans = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(ranks, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    // TC : O(m * √T)
    private boolean isPossible(int[] ranks, int n, int tarTime) {
        int donCnt = 0;  // no. of donouts can be made within tarTime
        for (int r : ranks) {
            
            int k = 1;
            int time = 0;
            
            while (true) {
                time += (k * r);
                if (time > tarTime) break;
                
                k ++;
                donCnt ++;

                if (donCnt >= n) return true;
            }
        }
        return donCnt >= n;
    }
}