// https://www.geeksforgeeks.org/problems/ticket-sellers3241/1/




import java.util.*;

class Solution {
    private int M = 1_000_000_007;
    public int maxAmount(int[] arr, int k) {
        PriorityQueue<Integer> maxH = new PriorityQueue<>(Collections.reverseOrder());
        for (int val : arr) {
            maxH.offer(val);
        }
        
        int result = 0;
        while(!maxH.isEmpty() && k > 0) {
            int val = maxH.poll();
            result = (result + val) % M;
            maxH.offer(val - 1);
            if (val == 0) break;
            k -= 1;
        }
        return result;
    }
}