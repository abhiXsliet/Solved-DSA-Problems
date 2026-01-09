// https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1/




import java.util.*;

class Solution {
    private int countAtMostKOddNo(int arr[], int k) {
        int n = arr.length;
        int cntOdd = 0;
        int i = 0;
        int j = 0;
        int result = 0;
        while (j < n) {
            if (arr[j] % 2 == 1) cntOdd += 1;
            while (cntOdd > k) {
                if (arr[i] % 2 == 1) cntOdd -= 1;
                i ++;
            }
            result += (j - i + 1);
            j ++;
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    private int approach_1(int[] arr, int k) {
        int n = arr.length;
        Map<Integer, Integer> hmp = new HashMap<>();
        hmp.put(0, 1);
        
        int ans = 0;
        int cumm_sm = 0;
        
        for (int val : arr) {
            cumm_sm += (val % 2 == 0) ? 0 : 1;
            if (hmp.containsKey(cumm_sm - k)) {
                ans += hmp.get(cumm_sm - k);
            }
            hmp.put(cumm_sm, hmp.getOrDefault(cumm_sm, 0) + 1);
        }
        
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    private int approach_2(int[] arr, int k) {
        return countAtMostKOddNo(arr, k) - countAtMostKOddNo(arr, k - 1);
    }
    public int countSubarrays(int[] arr, int k) {
        // return approach_1(arr, k);  // similar to problem : subarray sum equals k
        return approach_2(arr, k);  // exactly k subArr = at most k-subArr - at most (k - 1) subArr
    }
}