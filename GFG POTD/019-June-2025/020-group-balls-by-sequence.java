// https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1




import java.util.*;

class Solution {
    // TC : O(N * log(N))
    // SC : O(N)
    public boolean validgroup(int[] arr, int k) {
        int n = arr.length;
        
        if (k == 1) return true;
        if (n % k != 0) return false;
        
        Map<Integer, Integer> freq = new TreeMap<>();
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        
        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            int num = entry.getKey();
            int cnt = entry.getValue();
            if (cnt > 0) {
                for (int i = 1; i < k; i ++) {
                    int newNum = num + i;
                    if (freq.getOrDefault(newNum, 0) < cnt) {
                        return false;
                    }
                    freq.put(newNum, freq.get(newNum) - cnt);
                }
            }
        }
        return true;
    }
}