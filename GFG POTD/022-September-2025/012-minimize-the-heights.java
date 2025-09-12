// https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public int getMinDiff(int[] arr, int k) {
        int n = arr.length;
        
        Arrays.sort(arr);
        
        int maxEle = arr[n - 1], minEle = arr[0];
        int minDiff = maxEle - minEle;
        
        int maxi = 0, mini = 0;
        
        for (int i = 1; i < n; i ++) {
            if (arr[i] >= k) {
                maxi = Math.max(maxEle - k, arr[i - 1] + k);
                mini = Math.min(minEle + k, arr[i] - k);
                
                minDiff = Math.min(minDiff, maxi - mini);
            }
        }
        
        return minDiff;
    }
}