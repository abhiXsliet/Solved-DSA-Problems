// https://www.geeksforgeeks.org/problems/longest-periodic-proper-prefix/1




class Solution {
    // TC : O(N)
    // SC : O(N)
    int getLongestPrefix(String s) {
        int n = s.length();
        
        int[] lps = getLPS(s);
        
        int t = lps[n - 1];
        
        if (t == 0) return -1;
        
        while (lps[t - 1] > 0) t = lps[t - 1];
        
        return (n - t);
    }
    
    // TC : O(N)
    // SC : O(N)
    private int[] getLPS(String s) {
        int n = s.length();
        int[] lps = new int[n];
        int len = 0, j = 1;
        while (j < n) {
            if (s.charAt(j) == s.charAt(len)) {
                len += 1;
                lps[j] = len;
                j += 1;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[j] = len;
                    j += 1;
                }
            }
        }
        return lps;
    }
}