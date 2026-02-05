// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1/




class Solution {
    // TC : O(N)
    // SC : O(N)
    public int maxOnes(int arr[], int k) {
        int n = arr.length;
        
        int i = 0, j = 0, cntZero = 0;
        int result = 0;
        while (j < n) {
            if (arr[j] == 0) cntZero ++;
            while (i < j && cntZero > k) {
                if (arr[i] == 0) cntZero --;
                i ++;
            }
            result = Math.max(result, j - i + 1);
            j ++;
        }
        return result;
    }
}