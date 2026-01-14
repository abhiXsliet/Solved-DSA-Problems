// https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1/




class Solution {
    public int catchThieves(char[] arr, int k) {
        int n = arr.length;
        
        int i = 0, j = 0;   // police and thief pointers
        int totalCaught = 0;
        
        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') i ++;
            while (j < n && arr[j] != 'T') j ++;
            
            if (i < n && j < n && Math.abs(j - i) <= k) {
                i ++;
                j ++;
                totalCaught ++;
            } else {
                if (i < j) i ++;
                else j ++;
            }
        }
        
        return totalCaught;
    }
}