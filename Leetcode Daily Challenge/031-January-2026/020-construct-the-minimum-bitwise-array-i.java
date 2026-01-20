// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/




import java.util.*;

class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];

        for (int i = 0; i < n; i ++) {
            if (nums.get(i) == 2) {
                ans[i] = -1;
                continue;
            }

            for (int j = 0; j < 32; j ++) {
                if ((nums.get(i) & (1 << j)) > 0) {   // jth bit is set
                    continue;
                }
                // if the jth bit is not set
                // then unset the prev (j-1)th bit 
                int prev = j - 1;
                int val = (nums.get(i) ^ (1 << prev)); // ans[i]

                ans[i] = val;
                break;
            }
        }
        return ans;
    }
}