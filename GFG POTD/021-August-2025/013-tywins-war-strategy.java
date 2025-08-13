// https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1




import java.util.*;

class Solution {
    public int minSoldiers(int[] arr, int k) {
        int n = arr.length;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int req = (n + 1) / 2;
        
        for (int num : arr) {
            if (num % k == 0) {
                req -= 1;
                if (req == 0) return 0;
                continue;
            }    
            
            int quot = (num + k - 1) / k;   // ceil(num / k)
            int val  = (k * quot);
            pq.offer(val - num);
        }
        
        int ans = 0;
        while (req -- > 0 && !pq.isEmpty()) {
            ans += pq.poll();
        }
        return ans;
    }
}