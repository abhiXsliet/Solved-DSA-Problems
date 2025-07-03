// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int longestKSubstr(String s, int k) {
        int n = s.length();
        
        int[] freq = new int[26];
        
        int i = 0, j = 0, cnt = 0, len = -1;
        while (j < n) {
            freq[s.charAt(j) - 'a'] ++;
            if (freq[s.charAt(j) - 'a'] == 1) cnt += 1;
            
            while (i < j && cnt > k) {
                freq[s.charAt(i) - 'a'] --;
                if (freq[s.charAt(i) - 'a'] == 0) cnt --;
                i ++;
            }
            
            if (cnt == k) {
                len = Math.max(len, j - i + 1);
            }
            j ++;
        }
        return len;
    }
}