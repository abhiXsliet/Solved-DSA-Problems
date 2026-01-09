// https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(K)
    public int countAtMostK(int arr[], int k) {
        int n = arr.length;
        Map<Integer, Integer> hmp = new HashMap<>();
        int i = 0;
        int j = 0;
        int result = 0;
        while (j < n) {
            hmp.put(arr[j], hmp.getOrDefault(arr[j], 0) + 1);
            while (hmp.size() > k) {
                hmp.put(arr[i], hmp.get(arr[i]) - 1);
                if (hmp.get(arr[i]) == 0) hmp.remove(arr[i]);
                i ++;
            }
            result += (j - i + 1);
            j ++;
        }
        return result;
    }
}