// https://leetcode.com/problems/minimum-absolute-difference/




import java.util.*;

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(arr);

        int minDiff = Integer.MAX_VALUE;

        for (int i = 1; i < arr.length; i++) {
            minDiff = Math.min(minDiff, arr[i] - arr[i - 1]);
        }

        // Collect pairs with minimum difference
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.add(Arrays.asList(arr[i - 1], arr[i]));
            }
        }

        return result;
    }
}