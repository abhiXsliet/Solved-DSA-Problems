// https://www.geeksforgeeks.org/problems/count-the-subset-with-sum-equal-to-k/1/




import java.util.*;

class Solution {
    // TC : O(2^(n/2))
    // SC : O(2^(n/2)) auxiliary space
    // SC : O(n) recursive stack space
    public int countSubset(int[] arr, int k) {
        int n = arr.length;
        int mid = n / 2;

        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, n);

        Map<Integer, Integer> leftMap = new HashMap<>();

        // all subset sums of left
        genSums(left, 0, 0, leftMap);

        int[] ans = new int[1];
        genRight(right, 0, 0, leftMap, k, ans);

        return ans[0];
    }

    void genSums(int[] arr, int idx, int sum, Map<Integer, Integer> map) {
        if (idx == arr.length) {
            map.put(sum, map.getOrDefault(sum, 0) + 1);
            return;
        }
        genSums(arr, idx + 1, sum, map);
        genSums(arr, idx + 1, sum + arr[idx], map);
    }

    void genRight(int[] arr, int idx, int sum,
                  Map<Integer, Integer> leftMap,
                  int k, int[] ans) {
        if (idx == arr.length) {
            ans[0] += leftMap.getOrDefault(k - sum, 0);
            return;
        }
        genRight(arr, idx + 1, sum, leftMap, k, ans);
        genRight(arr, idx + 1, sum + arr[idx], leftMap, k, ans);
    }
}