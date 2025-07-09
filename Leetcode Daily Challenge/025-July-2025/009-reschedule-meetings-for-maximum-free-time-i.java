// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = startTime.length;

        List<Integer> gaps = new ArrayList<>();
        gaps.add(startTime[0]);
        for (int i = 1; i < n; i ++) {
            gaps.add(startTime[i] - endTime[i - 1]);
        }
        gaps.add(eventTime - endTime[n - 1]);

        // calculate prefix sum for the gaps
        for (int i = 1; i < gaps.size(); i ++) {
            gaps.set(i, (gaps.get(i) + gaps.get(i - 1)));
        }

        return maxGapWindowSizeK(gaps, k);
    }

    private int maxGapWindowSizeK(List<Integer> gaps, int k) {
        int n = gaps.size();

        int i = 0, j = k, maxGap = gaps.get(j);

        while (j < n) {
            if (j - i > k) i ++;

            int gap = (gaps.get(j) - ((i - 1) >= 0 ? gaps.get(i - 1) : 0));            
            maxGap  = Math.max(maxGap, gap);

            j ++;
        }

        return maxGap;
    }
}