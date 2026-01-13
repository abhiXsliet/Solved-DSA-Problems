// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1/




class Solution {
    private int cntSubstrAtMostK(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];
        int distinctCnt = 0;
        int i = 0, j = 0;
        int result = 0;
        while (j < n) {
            if (freq[s.charAt(j) - 'a'] == 0) distinctCnt += 1;
            freq[s.charAt(j) - 'a'] += 1;
            while (distinctCnt > k) {
                freq[s.charAt(i) - 'a'] -= 1;
                if (freq[s.charAt(i) - 'a'] == 0) distinctCnt -= 1;
                i ++;
            }
            result += (j - i + 1);
            j ++;
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    public int countSubstr(String s, int k) {
        return cntSubstrAtMostK(s, k) - cntSubstrAtMostK(s, k - 1);
    }
}