// https://leetcode.com/problems/longest-square-streak-in-an-array/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int longestSquareStreak(int[] nums) {
        HashSet<Integer> st = new HashSet<>();
        for (int num : nums) {
            st.add(num);
        }
        int maxStreak = 0;
        for (int num : nums) {
            long currNum = num;
            int subqLen = 0;
            while (currNum <= 1e5 && st.contains((int)currNum)) {   // At Worst : O(5)
                subqLen += 1;
                currNum *= currNum;
            }
            maxStreak = Math.max(maxStreak, subqLen);
        }
        return maxStreak < 2 ? - 1 : maxStreak;
    }
}