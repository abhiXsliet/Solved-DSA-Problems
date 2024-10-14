// https://leetcode.com/problems/maximal-score-after-applying-k-operations/


import java.util.*;

class Solution {
    public long maxKelements(int[] nums, int k) {
        long ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int num : nums) {
            pq.offer(num);
        }

        while (k -- > 0) {
            int topEl = pq.poll();
            ans += topEl;
            
            pq.offer( (topEl + 2) / 3 );
        }
        return ans;
    }
}