// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> result = new ArrayList<>();

        for (int num : nums) {
            while (!result.isEmpty()) {
                int prev = result.get(result.size() - 1);
                int gcdVal = getGCD(num, prev);

                if (gcdVal == 1) break;
                result.remove(result.size() - 1);

                int lcmVal = getLCM(num, prev);
                num = lcmVal;
            }
            result.add(num);
        }

        return result;
    }

    private static int getGCD(int a, int b) {
        return (b == 0) ? a : getGCD(b, a % b);
    }

    private static int getLCM(int a, int b) {
        return ((a / getGCD(a, b)) * b);
    }
}