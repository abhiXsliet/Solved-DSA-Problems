// https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public int romanToDecimal(String s) {
        int n = s.length();
        Map<Character, Integer> mpp = Map.of(
            'I', 1,
            'V', 5,
            'X', 10,
            'L', 50,
            'C', 100,
            'D', 500,
            'M', 1000
        );
        
        int result = mpp.get(s.charAt(n - 1));
        for (int i = n - 2; i >= 0; i --) {
            if (mpp.get(s.charAt(i)) < mpp.get(s.charAt(i + 1))) {
                result -= mpp.get(s.charAt(i));
            } else {
                result += mpp.get(s.charAt(i));
            }
        }
        return result;
    }
}