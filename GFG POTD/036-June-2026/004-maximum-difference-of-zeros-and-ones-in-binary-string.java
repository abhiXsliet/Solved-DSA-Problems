// https://www.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1




class Solution {
    int maxSubstring(String s) {
        int n = s.length();
        int i = 0, j = 0;
        int cntZeros = 0, cntOnes = 0, diff = 0;
        int maxLen = Integer.MIN_VALUE;
        while (j < n) {
            if (s.charAt(j) == '0') cntZeros += 1;
            else cntOnes += 1;
            
            diff = cntZeros - cntOnes;
            
            while (diff < 0) {
                if (s.charAt(i) == '0') cntZeros -= 1;
                else cntOnes -= 1;
                
                diff = cntZeros - cntOnes;
                i ++;
            }
            maxLen = Math.max(maxLen, diff);
            j ++;
        }
        return maxLen == 0 ? -1 : maxLen;
    }
}