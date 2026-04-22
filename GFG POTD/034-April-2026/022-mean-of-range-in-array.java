// https://www.geeksforgeeks.org/problems/mean-of-range-in-array2123/1/




import java.util.*;

class Solution {
    public ArrayList<Integer> findMean(int[] arr, int[][] queries) {
        int n = arr.length;
        int m = queries.length;
        
        int[] prefix = new int[n];
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i ++) {
            prefix[i] += prefix[i - 1] + arr[i];
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];
            int sum = prefix[r] - ((l - 1 >= 0) ? prefix[l - 1] : 0);
            int mean = sum / (r - l + 1);
            result.add(mean);
        }
        return result;
    }
}