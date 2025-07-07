// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/




import java.util.*;

class Solution {
    // TC : O(N*log(N))
    // SC : O(N)
    public int maxEvents(int[][] events) {
        int n = events.length;

        Arrays.sort(events, Comparator.comparingInt(a -> a[0]));

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int day = events[0][0]; // start at the closest starting day
        int i = 0;
        int attendedEvents = 0;

        while (!pq.isEmpty() || i < n) {
            if (pq.isEmpty()) {   // start of next event is ahead of current day
                day = events[i][0];
            }

            // Add all the events which could be attended on the current day
            while (i < n && day == events[i][0]) {
                pq.offer(events[i][1]);
                i ++;
            }

            // Attending the earliest possible event
            if (!pq.isEmpty()) {
                attendedEvents += 1;
                pq.poll();
            }

            day += 1;

            // Skip all those events whose endingTime < day
            while (!pq.isEmpty() && pq.peek() < day) {
                pq.poll();
            }
        }

        return attendedEvents;
    }
}