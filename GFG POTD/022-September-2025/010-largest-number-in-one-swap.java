// https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public String largestSwap(String s) {
        int n = s.length();
        
        Map<Integer, Integer> lastOcc = new HashMap<>();
        
        for (int i = 0; i < n; i ++) {
            lastOcc.put(s.charAt(i) - '0', i);
        }
        
        for (int i = 0; i < n; i ++) {
            int val = s.charAt(i) - '0';
            boolean isGreaterAvail = false;
            int digit = -1;
            
            for (int d = 9; d >= 0; d --) {
                if (lastOcc.containsKey(d) && lastOcc.get(d) > i && d > val) {
                    isGreaterAvail = true;
                    digit = d;
                    break;
                }
            }
            
            if (isGreaterAvail == true) {
                int j = lastOcc.get(digit);
                return swap(s, i, j);
            }
        }
        
        return s;
    }
    
    private static String swap(String s, int i, int j) {
        StringBuilder sb = new StringBuilder(s);
        char temp = sb.charAt(i);
        sb.setCharAt(i, sb.charAt(j));
        sb.setCharAt(j, temp);
        return sb.toString();
    }
}