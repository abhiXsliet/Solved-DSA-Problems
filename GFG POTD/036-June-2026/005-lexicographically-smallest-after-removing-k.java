// https://www.geeksforgeeks.org/problems/lexicographically-smallest-after-removing-k/1/




import java.util.*;

class Solution {
    private boolean isPowerOfTwo(int n) {
        return ((n > 0) && (n & (n - 1)) == 0);
    }
    public String lexicographicallySmallest(String s, int k) {
        int n = s.length();
        
        if (isPowerOfTwo(n)) {
            k /= 2;
        } else {
            k *= 2;
        }
        
        int rLen = n - k;
        
        if (rLen <= 0) return "-1";
        
        ArrayList<Character> stk = new ArrayList<>();
        
        for (int i = 0; i < n; i ++) {
            while (!stk.isEmpty() 
                && (stk.get(stk.size() - 1) > s.charAt(i)) 
                && ((stk.size() - 1 + (n - i)) >= rLen)) {
                stk.remove(stk.size() - 1);
            }
            if (stk.size() < rLen) {
                stk.add(s.charAt(i));
            }
        }
        
        StringBuilder res = new StringBuilder();
        for (char ch : stk) {
            res.append(ch);
        }
        return res.toString();
    }
}