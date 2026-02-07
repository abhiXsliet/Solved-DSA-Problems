// https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/




class Solution {
    int maxSum(int[] arr) {
        int n = arr.length;
        
        int currRotation  = 0;
        int totalSum      = 0;
        
        for (int i = 0; i < n; i ++) {
            currRotation += (i * arr[i]);
            totalSum += arr[i];
        }
        
        int maxVal = currRotation;
        for (int i = 1; i < n; i ++) {
            int nextRotation = ((currRotation + totalSum) - (n * arr[n - i]));
            maxVal = Math.max(maxVal, nextRotation);
            currRotation = nextRotation;
        }
        return maxVal;
    }
}