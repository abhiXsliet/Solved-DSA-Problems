// https://www.geeksforgeeks.org/problems/equal-to-product3836/1/




import java.util.*;
class Solution {
    public boolean isProduct(int[] arr, long target) {
        int n = arr.length;
        
        Map<Integer, Integer> mpp = new HashMap<>();
    
        for (int i = 0; i < n; i ++) {
            mpp.put(arr[i], mpp.getOrDefault(arr[i], 0) + 1);
        }
        
        if (target == 0) return mpp.getOrDefault(0, 0) >= 1;
        
        for (int i = 0; i < n; i ++) {
            if (arr[i] == 0) continue;
            long div = (target % (long) arr[i] == 0) ? (target / (long) arr[i]) : -1;
            if (div == -1) continue;
            if (div == arr[i]) return (mpp.getOrDefault((int) div, 0) > 1);
            if (mpp.getOrDefault((int) div, 0) >= 1) return true;
        }
        
        return false;
    }
}