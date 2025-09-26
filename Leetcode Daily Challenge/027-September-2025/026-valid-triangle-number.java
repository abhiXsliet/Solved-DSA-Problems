// https://leetcode.com/problems/valid-triangle-number/




import java.util.*;

class Solution {
    public int triangleNumber(int[] nums) {
        // return approach_1(nums);
        return approach_2(nums);
    }

    // TC : O(N^2)
    // SC : O(1)
    private static int approach_2(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);

        int result = 0;
        for (int k = n - 1; k >= 2; k --) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    result += (j - i);
                    j --;
                } else i ++;
            }
        }
        return result;
    }

    // TC : O(N^2 * log(N))
    // SC : O(1)
    private static int approach_1(int[] nums) {
        int n = nums.length;
        
        Arrays.sort(nums);

        int result = 0;
        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                int idx = lowerBound(nums, j, n, (nums[i] + nums[j]));
                int val = (idx - j - 1);
                result += (val <= 0) ? 0 : val;
            }
        }
        return result;
    }

    private static int lowerBound(int[] nums, int low, int high, int tar) {
        int ans = high;
        high -= 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= tar) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}