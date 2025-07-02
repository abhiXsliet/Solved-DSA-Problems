// https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public static String maxSubseq(String s, int k) {
        int n = s.length();
        
        StringBuilder result = new StringBuilder();
        
        for (int i = 0; i < n; i ++) {
            if (result.length() == 0 || result.charAt(result.length() - 1) > s.charAt(i)) {
                result.append(s.charAt(i));
            } else {
                while (k > 0 && result.length() > 0 && result.charAt(result.length() - 1) < s.charAt(i)) {
                    result.deleteCharAt(result.length() - 1);
                    k -= 1;
                } 
                result.append(s.charAt(i));
            }
        }
        while (k > 0 && result.length() > 0) {
            result.deleteCharAt(result.length() - 1);
            k -= 1;
        }
        return result.toString();
    }
}