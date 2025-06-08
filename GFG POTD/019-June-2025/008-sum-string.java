// https://www.geeksforgeeks.org/problems/sum-string3151/1

class Solution {
    // TC : O(N^3)
    // SC : O(N)
    public boolean isSumString(String s) {
        int n = s.length();
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j + i < n; j ++) {
                String first  = s.substring(0, i);
                String second = s.substring(i, i + j);
                
                // prevent leading zeros
                if ((first.length() > 1 && first.charAt(0) == '0') || (second.length() > 1 && second.charAt(0) == '0'))
                    continue;
                    
                if (isValid(s, n, first, second, i + j)) 
                    return true;
            }
        }
        return false;
    }
    // TC : O(N)
    // SC : O(N)
    private boolean isValid(String s, int n, String first, String second, int start) {
        while (start < n) {
            String sum = addStrings(first, second);
            int len = sum.length();
            if (start + len > n) return false;

            String third = s.substring(start, start + len);
            if (!third.equals(sum)) return false;
            
            first  = second;
            second = third;
            start += len;
        }
        return true;
    }
    private String addStrings(String first, String second) {
        int i = first.length() - 1, j = second.length() - 1, carry = 0;
        StringBuilder res = new StringBuilder();
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += (first.charAt(i --)  - '0');
            if (j >= 0) sum += (second.charAt(j --) - '0');
            
            carry = sum / 10;
            res.append(sum % 10);
        }
        return res.reverse().toString();
    }
}