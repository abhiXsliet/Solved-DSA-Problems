// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1




import java.util.*;

class Solution {
    public static String smallestWindow(String s, String p) {
        // return approach_1(s, p);
        return approach_2(s, p);
    }
    
    // TC : O(N + M)
    // SC : O(1)
    private static String approach_2(String s, String p) {
        int n = s.length(), m = p.length();
        
        Map<Character, Integer> mpp = new HashMap<>();
        for (char ch : p.toCharArray()) {
            mpp.put(ch, mpp.getOrDefault(ch, 0) + 1);
        }
        
        int count = mpp.size(), i = 0, j = 0, minLen = n, startIdx = -1;
        
        while (j < n) {
            char endCh = s.charAt(j);
            if (mpp.containsKey(endCh)) {
                mpp.put(endCh, mpp.get(endCh) - 1);
                if (mpp.get(endCh) == 0) {
                    count --;
                }
            }
            
            while (count == 0) {
                if (minLen > (j - i + 1)) {
                    minLen = (j - i + 1);
                    startIdx = i;
                }
                
                char startCh = s.charAt(i);
                if (mpp.containsKey(startCh)) {
                    mpp.put(startCh, mpp.get(startCh) + 1);
                    if (mpp.get(startCh) > 0) {
                        count ++;
                    }
                }
                
                i ++;
            }
            
            j ++;
        }
        
        return (startIdx == -1) ? "" : s.substring(startIdx, startIdx + minLen);
    }
    
    // TC : O(N + M)
    // SC : O(1)
    private static String approach_1(String s, String p) {
        int n = s.length(), m = p.length();
        
        int[] fp = new int[26];
        for (char ch : p.toCharArray()) fp[ch - 'a'] ++;
        
        int[] fs = new int[26];
        int i = 0, j = 0, minLen = n, startIdx = -1;
        
        while (j < n) {
            fs[s.charAt(j) - 'a'] ++;
            
            while (isAllAvailable(fs, fp)) {
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                
                fs[s.charAt(i) - 'a'] --;
                i ++;
            }
            
            j ++;
        }
        
        return (startIdx == -1) ? "" : s.substring(startIdx, startIdx + minLen);
    }
    
    private static boolean isAllAvailable(int[] fs, int[] fp) {
        for (int i = 0; i < 26; i ++) {
            if (fp[i] > 0 && fs[i] < fp[i])
                return false;
        }
        return true;
    }
}