// https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1




class Solution {
    private int n;
    
    // TC : O(N^2)
    // SC : O(1)
    public int countPS(String s) {
        n = s.length();
        int cntPalindromicSubstrs = 0;
        for (int i = 0; i < n; i ++) {
            cntPalindromicSubstrs += getPalindromicSubstr(s, i - 1, i + 1); // for odd length
            cntPalindromicSubstrs += getPalindromicSubstr(s, i, i + 1);     // for even length 
        }
        return cntPalindromicSubstrs;
    }
    
    private int getPalindromicSubstr(String s, int i, int j) {
        int cnt = 0;
        while (i >= 0 && j < n) {
            if (s.charAt(i) != s.charAt(j)) break;
            cnt += 1;
            i --;
            j ++;
        }
        return cnt;
    }
}