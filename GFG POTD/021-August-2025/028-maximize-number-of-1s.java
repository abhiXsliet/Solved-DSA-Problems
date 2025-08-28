// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int maxOnes(int arr[], int k) {
        int i = 0, maxLen = 0, cntZero = 0;
        
        for (int j = 0; j < arr.length; j ++) {
            cntZero += (arr[j] == 0) ? 1 : 0;
            
            while (cntZero > k) {
                cntZero -= (arr[i] == 0) ? 1 : 0;
                i ++;
            }
            
            maxLen = Math.max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
}