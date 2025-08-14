// https://leetcode.com/problems/largest-3-same-digit-number-in-string/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public String largestGoodInteger(String num) {
        int n = num.length();
        String result = "";
        for (int i = 0; i < n - 2; i ++) {
            if (num.charAt(i) == num.charAt(i + 1) && num.charAt(i + 1) == num.charAt(i + 2)) {
                String goodInteger = num.substring(i, i + 3);
                result = result.compareTo(goodInteger) < 0 ? goodInteger : result;
            }
        }
        return result;
    }
}