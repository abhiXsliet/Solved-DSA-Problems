// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] result = new int[n];
        for (int i = 0; i < n; i ++) {
            boolean isFound = false;
            for (int j = 0; j < 32; j ++) {
                if ((nums.get(i) & (1 << j)) > 0) {
                    continue;
                }
                int prev = j - 1;   // make this bit 0
                int val = (nums.get(i) ^ (1 << prev));
                result[i] = val;
                isFound = true;
                break;
            }
            if (!isFound || nums.get(i) == 2) result[i] = -1;
        }
        return result;
    }
}