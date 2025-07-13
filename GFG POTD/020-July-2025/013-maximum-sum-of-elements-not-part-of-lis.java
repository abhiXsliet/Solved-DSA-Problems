// https://www.geeksforgeeks.org/problems/maximum-sum-of-elements-not-part-of-lis/1




import java.util.*;

class Solution {
    public int nonLisMaxSum(int[] arr) {
        int n = arr.length;
        
        return approach_1(arr, n);
    }
    
    // TC : O(Nlog(N))
    // SC : O(N)
    private int approach_1(int[] arr, int n) {
        ArrayList<Integer> dp = new ArrayList<>(); // end elements of potential LIS
        
        int[] parent = new int[n];  // for reconstructing LIS
        int[] dpIdx = new int[n];   // index in original array for backtracking
        Arrays.fill(parent, -1);
        
        int totalSum = 0;
        
        for (int i = 0; i < n; i ++) {
            int pos = lowerBound(dp, arr[i]);
            
            if (pos == dp.size()) {
                dp.add(arr[i]);
            } else {
                dp.set(pos, arr[i]);
            }
            
            dpIdx[pos] = i;
            
            if (pos > 0) {
                parent[i] = dpIdx[pos - 1];
            }
            totalSum += arr[i];
        }
        
        // Reconstruct LIS
        List<Integer> lis = new ArrayList<>();
        int idx = dpIdx[dp.size() - 1];
        
        while (idx != -1) {
            lis.add(arr[idx]);
            idx = parent[idx];
        }
        
        int lisSum = 0;
        for (int i : lis) {
            lisSum += i;
        }
        
        return totalSum - lisSum;
    }
    
    private int lowerBound(List<Integer> arr, int tar) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (arr.get(mid) >= tar) {
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
}