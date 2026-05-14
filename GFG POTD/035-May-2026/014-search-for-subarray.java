// https://www.geeksforgeeks.org/problems/search-for-subarray/1/




import java.util.*;

class Solution {
    private int[] getLps(int[] pat, int n) {
        int[] lps = new int[n];
        
        for (int i = 1; i < n; i ++) {
            int j = lps[i - 1];
            while (j > 0 && pat[i] != pat[j]) {
                j = lps[j - 1];
            }
            if (pat[i] == pat[j]) j ++;
            lps[i] = j;
        }
        
        return lps;
    }
    
    public ArrayList<Integer> search(int[] a, int[] b) {
        int m = a.length;
        int n = b.length;
        
        int[] lps = getLps(b, n);
        
        ArrayList<Integer> res = new ArrayList<>();
        
        int i = 0, j = 0;
        
        while (i < m) {
            if (a[i] == b[j]) {
                i ++;
                j ++;
            } else {
                if (j != 0) j = lps[j - 1];
                else i ++;
            }
            
            if (j == n) {
                res.add(i - n);
                j = lps[j - 1];
            }
        }
        
        return res;
    }
}