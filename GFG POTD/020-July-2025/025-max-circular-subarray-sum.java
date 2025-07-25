// https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int maxCircularSum(int arr[]) {
        int total  = 0;
        int maxSum = Integer.MIN_VALUE, currMax = 0;
        int minSum = Integer.MAX_VALUE, currMin = 0;
        
        for (int num : arr) {
            currMax = Math.max(num, currMax + num); // maximum of previous subarray sum + curr_ele or only curr_ele
            maxSum  = Math.max(maxSum, currMax);
            
            currMin = Math.min(num, currMin + num); // minimum of previous subarray sum + curr_ele or only curr_ele
            minSum  = Math.min(minSum, currMin);
            
            total  += num;
        }
        
        return ((maxSum <= 0) ? maxSum : Math.max(maxSum, total - minSum));
    }
}