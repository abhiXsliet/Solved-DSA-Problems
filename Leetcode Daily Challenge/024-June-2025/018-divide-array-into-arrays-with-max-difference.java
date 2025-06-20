// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/




import java.util.*;

class Solution {
    // TC : O(N * log(N))
    // SC : O(1)
    public int[][] divideArray(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int[][] res = new int[n / 3][3];

        for (int i = 0; i <= n - 3; i += 3) {
            if (nums[i + 2] - nums[i] > k) 
                return new int[0][0];

            res[i / 3][0] = nums[i];
            res[i / 3][1] = nums[i + 1];
            res[i / 3][2] = nums[i + 2];
        }

        return res;
    }
}