// https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1/




class Solution {
    // TC : O(N)
    // SC : O(N)
    public int kBitFlips(int[] arr, int k) {
        int n = arr.length;
        int[] pSum = new int[n];
        int operations = 0;
        
        for (int i = 0; i < n; i ++) {
            if (i > 0) pSum[i] += pSum[i - 1];
            
            boolean isToggled = (pSum[i] % 2 == 0) ? false : true;
            
            if ((i > n - k) && ((arr[i] == 1 && isToggled) || (arr[i] == 0 && !isToggled)))
                return -1;
            
            if ((arr[i] == 1 && isToggled) || (arr[i] == 0 && !isToggled)) {
                pSum[i] += 1;
                if (i + k < n) pSum[i + k] -= 1;
                operations += 1;
            }
        }
        
        return operations;
    }
}