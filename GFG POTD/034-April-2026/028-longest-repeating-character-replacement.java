// https://www.geeksforgeeks.org/problems/longest-repeating-character-replacement/1/




class Solution {
    private int cntOfOpr(int[] freq) {
        int maxEleCnt = 0, totalEleCnt = 0;
        for (int i = 0; i < 26; i ++) {
            maxEleCnt = Math.max(maxEleCnt, freq[i]);
            totalEleCnt += freq[i];
        }
        return totalEleCnt - maxEleCnt;
    }
    
    // TC : O(N)
    // SC : O(1)
    public int longestSubstr(String s, int k) {
        int n = s.length();
        
        int[] freq = new int[26];
        
        int i = 0, j = 0;
        int longestSubstr = 0;
        
        while (j < n) {
            freq[s.charAt(j) - 'A'] += 1;
            
            while (cntOfOpr(freq) > k) {
                freq[s.charAt(i) - 'A'] -= 1;
                i ++;
            }
            
            longestSubstr = Math.max(longestSubstr, j - i + 1);
            
            j ++;
        }
        
        return longestSubstr;
    }
}