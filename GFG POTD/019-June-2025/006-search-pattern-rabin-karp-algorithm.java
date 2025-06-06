// https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1




import java.util.*;

class Solution {
    private static final int M = 1_000_000_007;
    
    // TC : O(M + N)
    // SC : O(1)
    ArrayList<Integer> search(String pat, String txt) {
        int m = pat.length(), n = txt.length();
        ArrayList<Integer> result = new ArrayList<>();
        
        long powerM = 1;
        for (int i = 1; i <= m; i ++) {
            powerM = (powerM * 26) % M;
        }
        
        long hashPat = getHash(pat);
        long hashTxt = 0;
        
        for (int i = 0; i <= n - m; i ++) {
            if (i == 0) {
                String str = txt.substring(i, i + m);
                hashTxt = getHash(str);
            } else {
                hashTxt = (hashTxt * 26 - (powerM * (txt.charAt(i - 1) - 'a')) + (txt.charAt(i + m - 1) - 'a')) % M;
                hashTxt = (hashTxt + M) % M;
            }
            
            if (hashTxt == hashPat) {
                int j = 0;
                for (; j < m; j ++) {
                    if (txt.charAt(i + j) != pat.charAt(j)) break;
                }
                if (j == m) {
                    result.add(i + 1);
                }
            }
        }
        
        return result;
    }
    
    private long getHash(String s) {
        long ans = 0, factor = 1;
        for (int i = s.length() - 1; i >= 0; i --) {
            ans    = (ans + factor * (s.charAt(i) - 'a')) % M;
            factor = (factor * 26) % M;
        }
        return ans % M;
    }
}