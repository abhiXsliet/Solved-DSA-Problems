// https://www.geeksforgeeks.org/problems/divisible-by-13/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public boolean divby13(String s) {
        int n = s.length();
        int rem = 0;
        for (int i = 0; i < n; i ++) {
            int dividend = (rem * 10 + (s.charAt(i) - '0'));
            rem = dividend % 13;
        }
        return (rem == 0);
    }
}