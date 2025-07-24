// https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1




class Solution {
    // TC : O(N + M) Where N = length of right and M = length of left
    // SC : O(1)
    public int getLastMoment(int n, int left[], int right[]) {
        int lastTime = Integer.MIN_VALUE;
        for (int i = 0; i < right.length; i ++) {
            lastTime = Math.max(lastTime, n - right[i]);
        }
        for (int i = 0; i < left.length; i ++) {
            lastTime = Math.max(lastTime, left[i]);
        }
        return lastTime;
    }
}