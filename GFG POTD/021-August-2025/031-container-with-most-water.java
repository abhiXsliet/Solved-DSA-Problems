// https://www.geeksforgeeks.org/problems/container-with-most-water0535/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int maxWater(int arr[]) {
        int n = arr.length;
        
        int i = 0, j = n - 1, maxWaterCollected = 0;
        
        while (i < j) {
            int waterCollected = (j - i) * Math.min(arr[i], arr[j]);
            maxWaterCollected  = Math.max(maxWaterCollected, waterCollected);
            
            if (arr[i] < arr[j]) i ++;
            else j --;
        }
        
        return maxWaterCollected;
    }
}