// https://leetcode.com/problems/minimum-removals-to-balance-array/




import java.util.*;

class Solution {
    public int minRemoval(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int largestBalancedLen = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (i < j && (long)nums[i] * k < nums[j]) i ++;
            largestBalancedLen = Math.max(largestBalancedLen, j - i + 1);
            j ++;
        }
        return (n - largestBalancedLen);
    }
}