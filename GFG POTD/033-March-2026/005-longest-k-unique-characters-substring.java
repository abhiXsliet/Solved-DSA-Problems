// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/




class Solution {
    public int longestKSubstr(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];
        int i = 0, j = 0, count = 0, maxLen = -1;
        
        while (j < n) {
            if (freq[s.charAt(j) - 'a'] == 0) {
                count += 1;
            }
            freq[s.charAt(j) - 'a'] += 1;
            
            while (count > k && i < j) {
                freq[s.charAt(i) - 'a'] -= 1;
                if (freq[s.charAt(i) - 'a'] == 0) count -= 1;
                i ++;
            }
            
            if (count == k) {
                maxLen = Math.max(maxLen, j - i + 1);
            }
            
            j ++;
        }
        
        return maxLen;
    }
}