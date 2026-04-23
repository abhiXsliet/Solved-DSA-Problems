// https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1/




class Solution {
    public boolean canSplit(int arr[]) {
        int n = arr.length;
        
        if (n == 1) return false;
        
        int s1 = arr[0], s2 = arr[n - 1];
        int i = 0, j = n - 1;
        
        while (i <= j) {
            if (s1 < s2) {
                i ++;
                if (i >= j) break;
                s1 += arr[i];
            } else if (s2 < s1) {
                j --;
                if (i >= j) break;
                s2 += arr[j];
            } else {
                i ++;
                j --;
                if (i == j) s1 += arr[i];
                if (i >= j) break;
                s1 += arr[i];
                s2 += arr[j];
            }
        }
        
        return s1 == s2;
    }
}