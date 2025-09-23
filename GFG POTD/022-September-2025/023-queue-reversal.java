// https://www.geeksforgeeks.org/problems/queue-reversal/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public void reverseQueue(Queue<Integer> q) {
        Stack<Integer> stk = new Stack<>();
        while (!q.isEmpty()) {
            stk.push(q.poll());
        }
        while (!stk.isEmpty()) {
            q.offer(stk.pop());
        }
    }
}