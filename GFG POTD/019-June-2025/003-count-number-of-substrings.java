// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1




import java.util.*;

// User function Template for Java

class Solution {
    int countSubstr(String s, int k) {
        // return approach_1(s, k); // 2-pass soln.
        return approach_2(s, k); // 1-pass soln.
    }
    
    // TC : O(N)
    // SC : O(1) 
    int approach_2(String s, int k) {
        int n = s.length();
        List<Integer> freq = new ArrayList<>(Collections.nCopies(26, 0));
        int cntFreq = 0;
        
        int i = 0, j = 0, prev_i = 0;   // prev_i will track index of starting valid substring
        int cntSubstr = 0;
        
        while (j < n) {
            int idx = s.charAt(j) - 'a';
            freq.set(idx, freq.get(idx) + 1);
            if (freq.get(idx) == 1) cntFreq += 1;
            
            while (cntFreq > k) {
                int chI = s.charAt(i) - 'a';
                freq.set(chI, freq.get(chI) - 1);
                if (freq.get(chI) == 0) {
                    cntFreq --;
                }
                i ++;
                prev_i = i;
            }
            
            while (i < j && freq.get(s.charAt(i) - 'a') > 1) {
                int chI = s.charAt(i) - 'a';
                freq.set(chI, freq.get(chI) - 1);
                i ++;
            }
            
            if (cntFreq == k) cntSubstr += (i - prev_i + 1);
            j ++;
        }
        
        return cntSubstr;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_1(String s, int k) {
        int totalCnt = getSubStringCnt(s, k);       // substrings contains distinct chars at most k-times
        int remains  = getSubStringCnt(s, k - 1);   // substrings contains distinct chars at most k-1 times
    
        return totalCnt - remains;  // substrings contains distinct chars exactly k-times
    }
    
    // TC : O(N)
    // SC : O(1)
    int getSubStringCnt(String s, int k) {
        int n = s.length();
        
        int[] freq = new int[26];
        for (int i = 0; i < 26; i ++) {
            freq[i] = 0;
        }
        
        int i = 0, j = 0, ans = 0;
        int cntFreq = 0;
        
        while (j < n) {
            freq[s.charAt(j) - 'a'] ++;
            if (freq[s.charAt(j) - 'a'] == 1) cntFreq += 1;
            
            while (i <= j && cntFreq > k) {
                freq[s.charAt(i) - 'a'] --;
                if (freq[s.charAt(i) - 'a'] == 0) {
                    cntFreq --;
                }
                i ++;
            }
            
            ans += (j - i + 1);
            j ++;
        }
        
        return ans;
    }
}