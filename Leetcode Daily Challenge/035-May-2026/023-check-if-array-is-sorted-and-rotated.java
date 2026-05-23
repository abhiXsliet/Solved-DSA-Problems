// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/




class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int broke = 0;
        for (int i = 1; i <= n; i ++) {
            if (nums[i % n] >= nums[i - 1]) continue;
            else {
                if (broke == 1) return false;
                broke += 1;
            }
        }
        return true;
    }
}