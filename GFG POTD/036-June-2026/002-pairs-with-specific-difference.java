// https://www.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1/



import java.util.*;

class Solution {
    public int sumDiffPairs(int[] arr, int k) {
        int n = arr.length;
        Arrays.sort(arr);
        
        int result = 0;
        for (int i = n - 1; i > 0; i --) {
            if (Math.abs(arr[i] - arr[i - 1]) < k) {
                result += arr[i];
                result += arr[i - 1];
                i --;
            }
        }
        return result;
    }
}