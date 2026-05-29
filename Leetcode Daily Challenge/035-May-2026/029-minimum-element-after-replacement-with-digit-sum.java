// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/




class Solution {
    private int getDigitSum(int val) {
        int sum = 0;
        while (val > 0) {
            sum += (val % 10);
            val /= 10;
        }
        return sum;
    }
    public int minElement(int[] nums) {
        int ans = Integer.MAX_VALUE;
        for (int num : nums) {
            ans = Math.min(ans, getDigitSum(num));
        }
        return ans;
    }
}