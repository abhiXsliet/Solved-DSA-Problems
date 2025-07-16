// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/




class Solution {
    public int maximumLength(int[] nums) {
        int n = nums.length;

        int odds = 0, evens = 0, oddEven = 0, evenOdd = 0;
        boolean isOdd = false, isEven = false;

        for (int i = 0; i < n; i ++) {
            if (nums[i] % 2 == 0) evens += 1;
            else odds += 1;

            if (!isEven && nums[i] % 2 == 1) {
                oddEven += 1;
                isEven   = true;
            } else if (isEven && nums[i] % 2 == 0) {
                oddEven += 1;
                isEven   = false;
            }

            if (!isOdd && nums[i] % 2 == 0) {
                evenOdd += 1;
                isOdd    = true;
            } else if (isOdd && nums[i] % 2 == 1) {
                evenOdd += 1;
                isOdd    = false;
            }
        }

        return Math.max(odds, Math.max(evens, Math.max(evenOdd, oddEven)));
    }
}