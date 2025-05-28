// https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1




class Solution {
    public static int sumSubstrings(String s) {
        int n = s.length();
        long result = 0;
        long prev   = 0;
        for (int i = 0; i < n; i ++) {
            int num = s.charAt(i) - '0';
            prev = prev * 10 + (num * (i + 1));
            result += prev;
        }
        return (int)result;
    }
}