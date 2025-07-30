// https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int cntSubarrays(int[] arr, int k) {
        Map<Integer, Integer> mpp = new HashMap<>();
        mpp.put(0, 1);
        int sum = 0, cnt = 0;
        for (int num : arr) {
            sum += num;
            cnt += mpp.getOrDefault(sum - k, 0);
            mpp.put(sum, mpp.getOrDefault(sum, 0) + 1);
        }
        return cnt;
    }
}