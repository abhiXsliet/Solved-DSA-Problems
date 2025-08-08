// https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1




class Solution {
    private int n;
    
    int getLPSLength(String s) {
        n = s.length();
        
        // return approach_1(s);   
        // return approach_2(s);   // No extra while loop
        return approach_3(s);   // Rolling Hash : O(1) space
    }
    
    private int approach_3(String s) {
        long[] prefixHash = new long[2];
        long[] suffixHash = new long[2];
        
        final long base1 = 31, base2 = 37, M1 = 1000_000_000 + 7, M2 = 1000_000_000 + 9;
        long p1 = 1, p2 = 1, ans = 0;
    
        for (int i = 0; i < n - 1; i ++) {  // len 0 to n - 1
            prefixHash[0] = ( prefixHash[0] + ((s.charAt(i) - 'a' + 1) * p1 % M1) ) % M1;
            prefixHash[1] = ( prefixHash[1] + ((s.charAt(i) - 'a' + 1) * p2 % M2) ) % M2;
            
            suffixHash[0] = ( (suffixHash[0] * base1) % M1 + (s.charAt(n - i - 1) - 'a' + 1) ) % M1;
            suffixHash[1] = ( (suffixHash[1] * base2) % M2 + (s.charAt(n - i - 1) - 'a' + 1) ) % M2;
            
            if (prefixHash[0] == suffixHash[0] && prefixHash[1] == suffixHash[1]) {
                ans = i + 1;
            }
            
            p1 = p1 * base1 % M1;
            p2 = p2 * base2 % M2;
        }
        
        return (int)ans;
    }   
        
    // TC : O(N)
    // SC : O(N)
    private int approach_1(String s) {
        int[] lps = new int[n];
        for (int i = 1; i < n; i ++) {
            int j = lps[i - 1];
            
            while (j > 0 && s.charAt(i) != s.charAt(j)) j = lps[j - 1];
            
            if (s.charAt(i) == s.charAt(j)) j ++;
            
            lps[i] = j;
        }
        return lps[n - 1];
    }

    // TC : O(N)
    // SC : O(N)
    private int approach_2(String s) {
        int[] lps = new int[n];
        int len = 0, j = 1;
        while (j < n) {
            if (s.charAt(j) == s.charAt(len)) {
                len ++;
                lps[j] = len;
                j ++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[j] = len;
                    j ++;
                }
            }
        }
        return lps[n - 1];
    }
}