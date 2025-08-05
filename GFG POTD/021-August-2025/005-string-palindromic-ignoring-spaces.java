// https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public boolean isPalinSent(String s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i <= j && (s.charAt(i) == ' ' || !Character.isLetterOrDigit(s.charAt(i)))) i ++;
            while (i <= j && (s.charAt(j) == ' ' || !Character.isLetterOrDigit(s.charAt(j)))) j --;
            
            if (i >= j) break;
            
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j)))
                return false;
                
            i ++;
            j --;
        }
        return true;
    }
}