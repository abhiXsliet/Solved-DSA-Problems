// https://leetcode.com/problems/fraction-to-recurring-decimal/




import java.util.*;

class Solution {
    // TC : O(deno + length)
    // SC : O(deno)
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        StringBuilder result = new StringBuilder();

        if ((long)numerator * denominator < 0) {
            result.append("-");
        }

        long absNum = Math.abs((long)numerator);
        long absDen = Math.abs((long)denominator);

        long div = absNum / absDen;
        result.append(div);
        
        long rem = absNum % absDen;
        if (rem == 0) return result.toString();

        result.append(".");
        Map<Long, Integer> mpp = new HashMap<>();

        while (rem > 0) {
            if (mpp.containsKey(rem)) {
                result.insert(mpp.get(rem), "(");
                result.append(")");
                break;
            }

            mpp.put(rem, result.length());

            rem *= 10;
            long digit = rem / absDen;

            result.append(digit);
            rem %= absDen;
        }

        return result.toString();
    }
}