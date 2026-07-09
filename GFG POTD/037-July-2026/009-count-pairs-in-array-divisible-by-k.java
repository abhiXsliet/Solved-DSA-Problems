// https://www.geeksforgeeks.org/problems/count-pairs-in-array-divisible-by-k/1/




import java.util.*;

class Solution {
    public int countKdivPairs(int[] arr, int k) {
        Map<Integer, Integer> mpp = new HashMap<>();
        int ans = 0;
        for (int val : arr) {
            int num = val % k;
            ans += (num == 0) ? mpp.getOrDefault(num, 0) : mpp.getOrDefault(k - num, 0);
            mpp.put(num, mpp.getOrDefault(num, 0) + 1);
        }
        return ans;
    }
}