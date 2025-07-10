// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/




class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;

        int[] gaps = new int[n + 1];
        gaps[0] = (startTime[0]);
        for (int i = 1; i < n; i ++) {
            gaps[i] = (startTime[i] - endTime[i - 1]);
        }
        gaps[n] = (eventTime - endTime[n - 1]);

        int[] prefix = new int[n + 1];
        prefix[0] = gaps[0];

        int[] suffix = new int[n + 1];
        suffix[n] = gaps[n];

        for (int i = 1; i <= n; i ++) {
            prefix[i]     = Math.max(prefix[i - 1], gaps[i]);
            suffix[n - i] = Math.max(suffix[n - i + 1], gaps[n - i]);
        }

        int maxFreeTime = 0;

        for (int i = 0; i < n; i ++) {
            int meetTime = (endTime[i] - startTime[i]);

            int freeTimeReschedule = 0;
            if ( ((i > 0) && prefix[i - 1] >= meetTime) || ((i + 2 <= n) && meetTime <= suffix[i + 2]) ) {
                freeTimeReschedule = (meetTime + gaps[i] + gaps[i + 1]);
            }

            int freeTimeHover = (gaps[i] + gaps[i + 1]);

            maxFreeTime = Math.max(maxFreeTime, Math.max(freeTimeReschedule, freeTimeHover));
        }

        return maxFreeTime;
    }
}