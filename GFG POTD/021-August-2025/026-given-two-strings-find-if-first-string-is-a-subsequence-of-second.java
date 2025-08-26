// https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1




class Solution {
    // TC : O(M + N)
    // SC : O(1)
    public boolean isSubSeq(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s1.charAt(i) == s2.charAt(j)) {
                i ++;
                j ++;
            } else j ++;
        }
        return (i == m);
    }
};