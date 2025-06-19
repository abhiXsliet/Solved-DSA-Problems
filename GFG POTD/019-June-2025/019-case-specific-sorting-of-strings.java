// https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1




class Solution {
    // TC : O(N*log(N))
    // SC : O(1)
    public static String caseSort(String s) {
        int n = s.length();
        int[] lower = new int[26];
        int[] upper = new int[26];
        
        for (char ch : s.toCharArray()) {
            if (Character.isLowerCase(ch)) {
                lower[ch - 'a'] += 1;
            } else if (Character.isUpperCase(ch)) {
                upper[ch - 'A'] += 1;
            }
        }
        
        StringBuilder res = new StringBuilder();
        int i = 0, j = 0;
        
        for (int idx = 0; idx < n; idx ++) {
            char ch = s.charAt(idx);
            if (Character.isLowerCase(ch)) {
                while (lower[i] == 0) i ++;
                res.append((char)(i + 'a'));
                lower[i] --;
            } else if (Character.isUpperCase(ch)) {
                while (upper[j] == 0) j ++;
                res.append((char)(j + 'A'));
                upper[j] --;
            }
        }
        
        return res.toString();
    }
}