// https://leetcode.com/problems/fruit-into-baskets/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        Map<Integer, Integer> mpp = new HashMap<>();
        int i = 0, j = 0, maxFruits = 0;
        while (j < n) {
            mpp.put(fruits[j], mpp.getOrDefault(fruits[j], 0) + 1);
            while (mpp.size() > 2) {
                mpp.put(fruits[i], mpp.get(fruits[i]) - 1);
                if (mpp.get(fruits[i]) == 0) {
                    mpp.remove(fruits[i]);
                }
                i ++;
            }
            maxFruits = Math.max(maxFruits, j - i + 1);
            j ++;
        }
        return maxFruits;
    }
}