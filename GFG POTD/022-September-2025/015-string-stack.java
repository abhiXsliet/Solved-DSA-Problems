// https://www.geeksforgeeks.org/problems/string-stack--165812/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public boolean stringStack(String pat, String tar) {
        int m = pat.length(), n = tar.length();
        
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (pat.charAt(i) == tar.charAt(j)) {
                i --;
                j --;
            } else {
                i -= 2;
            }
        }
        return (j < 0);
    }
}