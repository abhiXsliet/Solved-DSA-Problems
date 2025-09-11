// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int minJumps(int[] arr) {
        int n = arr.length;
        int jumps = 0, maxRange = 0, end = 0;
        for (int i = 0; i < n - 1; i ++) {
            maxRange = Math.max(maxRange, i + arr[i]);
            if (i == end) {
                jumps += 1;
                end    = maxRange;
                if (end == i) return -1;
            }
        }
        return jumps;
    }
}