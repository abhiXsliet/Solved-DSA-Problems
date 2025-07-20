// https://www.geeksforgeeks.org/problems/count-numbers-containing-specific-digits/1




import java.util.*;

class Solution {
    // TC : O(1)
    // SC : O(1)
    public int countValid(int n, int[] arr) {
        Set<Integer> st = new HashSet<>();
        boolean isZero = false;
        for (int num : arr) {
            if (num != 0) {
                st.add(num);
            } else isZero = true;
        }
        
        int size  = st.size();
        int badNo = 9 - size;
        int val   = badNo + ((isZero == true) ? 0 : 1);
        int total = 9;
        
        for (int i = 1; i < n; i ++) {
            total *= 10;
            badNo *= val;
        }
        
        return (total - badNo);
    }
}