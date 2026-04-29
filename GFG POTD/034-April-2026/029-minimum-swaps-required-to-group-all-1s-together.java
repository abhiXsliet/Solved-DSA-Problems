// https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1/




class Solution {
    public int minSwaps(int[] arr) {
        int n = arr.length;
        
        int cntOnes = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] == 1) cntOnes += 1;
        }
        
        int i = 0, j = 0, windowZero = 0;
        int minSwaps = n;
        
        while (j < n) {
            if (arr[j] == 0) windowZero += 1;
            if (j - i + 1 == cntOnes) {
                minSwaps = Math.min(minSwaps, windowZero);
                if (arr[i] == 0) windowZero -= 1;
                i ++;
            }
            j ++;
        }
        
        return minSwaps == n ? -1 : minSwaps;
    }
}