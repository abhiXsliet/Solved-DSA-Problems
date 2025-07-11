// https://leetcode.com/problems/meeting-rooms-iii/




import java.util.*;

class Solution {
    // TC : O(M*log(M) + M*log(N))
    // SC : O(M + N)
    public int mostBooked(int n, int[][] meetings) {

        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<Integer> freeRooms = new PriorityQueue<>();

        PriorityQueue<long[]> ongoing = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Long.compare(a[0], b[0]);
            return Integer.compare((int)a[1], (int)b[1]);
        });

        int[] roomUsedTimesCnt = new int[n];

        for (int i = 0; i < n; i ++) {
            freeRooms.offer(i);
        }

        for (int[] meet : meetings) {
            int currMeetStart = meet[0], currMeetEnd = meet[1];

            // Freeing up rooms whose meeting has ended
            while (!ongoing.isEmpty() && ongoing.peek()[0] <= currMeetStart) {
                int room = (int)ongoing.poll()[1];
                freeRooms.offer(room);
            }

            if (!freeRooms.isEmpty()) {
                int room = freeRooms.poll();
                ongoing.offer(new long[]{currMeetEnd, room});
                roomUsedTimesCnt[room] ++;
            } else {
                long[] it = ongoing.poll();
                long earlyEnd  = it[0]; // next starting time of meeting
                int earlyRoom  = (int) it[1]; // available room for next meeting

                long duration   = currMeetEnd - currMeetStart;
                long newMeetEnd = earlyEnd + duration;

                roomUsedTimesCnt[earlyRoom] ++;
                ongoing.offer(new long[]{newMeetEnd, earlyRoom});
            }
        }

        int minRoom = 0, maxUsed = 0;
        for (int i = 0; i < n; i ++) {
            if (roomUsedTimesCnt[i] > maxUsed) {
                maxUsed = roomUsedTimesCnt[i];
                minRoom = i;
            }
        }
        return minRoom;
    }
}