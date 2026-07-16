// https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/




import java.util.*;

class Solution {
    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] prefixGcd = new int[n];
        int maxi = 0;
        for (int i = 0; i < n; i ++) {
            maxi = Math.max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        Arrays.sort(prefixGcd);

        long result = 0;
        for (int i = 0; i < n/2; i ++) {
            if (i == n - i - 1) break;
            result += gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }
        return result;
    }
    private int gcd(int a, int b) {
        return (b == 0) ? Math.abs(a) : gcd(b, a % b);
    }
}