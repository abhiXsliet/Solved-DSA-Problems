// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/




import java.util.*;

class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        Collections.sort(arr);
        int i = 0, j = m - 1;
        int result = Integer.MAX_VALUE;
        while (j < arr.size()) {
            result = Math.min(result, arr.get(j) - arr.get(i));
            i ++;
            j ++;
        }
        return result;
    }
}