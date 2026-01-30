// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1/




import java.util.*;

class Solution {
    public void rearrangeQueue(Queue<Integer> q) {
        int n = q.size();
        Queue<Integer> first = new LinkedList<>();

        // Step 1: take first half
        for (int i = 0; i < n / 2; i++) {
            first.offer(q.poll());
        }

        // Step 2: interleave
        while (!first.isEmpty()) {
            q.offer(first.poll());
            q.offer(q.poll());
        }
    }
}