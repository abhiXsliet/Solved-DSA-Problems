// https://www.geeksforgeeks.org/problems/design-minmax-queue/1/




import java.util.*;

// TC : O(1) for all methods
// SC : O(N) 
class SpecialQueue {
    private Queue<Integer> q;
    private Deque<Integer> minQ;
    private Deque<Integer> maxQ;
    
    public SpecialQueue() {
        q = new LinkedList<>();
        minQ = new LinkedList<>();
        maxQ = new LinkedList<>();
    }

    public void enqueue(int x) {
        q.offer(x);
        
        while (!minQ.isEmpty() && minQ.peekLast() > x) minQ.pollLast();
        minQ.offerLast(x);
        
        while (!maxQ.isEmpty() && maxQ.peekLast() < x) maxQ.pollLast();
        maxQ.offerLast(x);
    }

    public void dequeue() {
        if (q.isEmpty()) return;
        int front = q.poll();
        
        if (!minQ.isEmpty() && front == minQ.peekFirst()) minQ.pollFirst();
        if (!maxQ.isEmpty() && front == maxQ.peekFirst()) maxQ.pollFirst();
    }

    public int getFront() {
        return q.isEmpty() ? -1 : q.peek();
    }

    public int getMin() {
        return minQ.isEmpty() ? -1 : minQ.peekFirst();
    }

    public int getMax() {
        return maxQ.isEmpty() ? -1 : maxQ.peekFirst();
    }
}