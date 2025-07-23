// https://leetcode.com/problems/maximum-score-from-removing-substrings/




import java.util.*;

class Solution {
    public int maximumGain(String s, int x, int y) {
        // return approach_1(s, x, y);
        return approach_2(s, x, y);  // no stack : two pointer (i, j) => i reads while j writes
    }

    // TC : O(N)
    // SC : O(1)
    private int approach_2(String s, int x, int y) {
        int total = 0;
        if (x > y) {
            Pair result1 = getRemainingStringWithPointsWithoutStack(s, 'a', 'b', x);    // first remove "ab"
            Pair result2  = getRemainingStringWithPointsWithoutStack(result1.s, 'b', 'a', y);   // now remove "ba"
            total = result1.val + result2.val;
        } else {
            Pair result1 = getRemainingStringWithPointsWithoutStack(s, 'b', 'a', y);    // first remove "ba"
            Pair result2  = getRemainingStringWithPointsWithoutStack(result1.s, 'a', 'b', x);   // now remove "ab"
            total = result1.val + result2.val;
        }
        return total;
    }

    // TC : O(N)
    // SC : O(N)
    private int approach_1(String s, int x, int y) {
        int total = 0;
        if (x > y) {
            Pair result1 = getRemainingStringWithPoints(s, 'a', 'b', x);    // first remove "ab"
            Pair result2  = getRemainingStringWithPoints(result1.s, 'b', 'a', y);   // now remove "ba"
            total = result1.val + result2.val;
        } else {
            Pair result1 = getRemainingStringWithPoints(s, 'b', 'a', y);    // first remove "ba"
            Pair result2  = getRemainingStringWithPoints(result1.s, 'a', 'b', x);   // now remove "ab"
            total = result1.val + result2.val;
        }
        return total;
    }

    public static class Pair{
        public String s;
        public int val;
        Pair(String str, int value) {
            this.s = str;
            this.val = value;
        }
    }

    private Pair getRemainingStringWithPoints(String s, char ch1, char ch2, int pointsPerPair) {
        Stack<Character> stk = new Stack<>();
        int points = 0;
        for (char ch : s.toCharArray()) {
            if (!stk.isEmpty() && stk.peek() == ch1 && ch == ch2) {
                stk.pop();
                points += pointsPerPair;
            } else stk.push(ch);
        }
        StringBuilder newStr = new StringBuilder();
        while (!stk.isEmpty()) {
            newStr.append(stk.pop());
        }
        return new Pair(newStr.reverse().toString(), points);
    }

    private Pair getRemainingStringWithPointsWithoutStack(String s, char ch1, char ch2, int pointsPerPair) {
        int n = s.length();
        int points = 0;
        int i = 0, j = 0;
        StringBuilder sb = new StringBuilder(s);
        while (j < n) {
            sb.setCharAt(i, sb.charAt(j));
            i ++;

            if ((i - 2 >= 0) && sb.charAt(i - 2) == ch1 && sb.charAt(i - 1) == ch2) {
                i -= 2;
                points += pointsPerPair;
            }

            j ++;
        }
        String remaining = sb.substring(0, i);
        return new Pair(remaining, points);
    }    
}