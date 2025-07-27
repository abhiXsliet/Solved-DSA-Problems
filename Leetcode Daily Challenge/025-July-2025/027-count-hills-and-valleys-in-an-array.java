// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int countHillValley(int[] nums) {
        int n = nums.length;
        int i = 1, total = 0;
        while (i < n - 1) {
            int prev = nums[i - 1];
            while (i < n - 1 && nums[i] == nums[i + 1]) i ++;
            if (i < n - 1 && ((prev > nums[i] && nums[i] < nums[i + 1]) || // Valley
                             (prev < nums[i] && nums[i] > nums[i + 1]))) { // Hill
                total += 1;
            }
            i ++;
        }
        return total;
    }
}