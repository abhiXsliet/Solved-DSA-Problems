// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/




import java.util.*;

class Solution {
    // TC : O(N^2)
    // SC : O(1)
    public int numberOfPairs(int[][] points) {
        int n = points.length;

        Arrays.sort(points, (p1, p2) -> {
            if (p1[0] == p2[0]) {
                return Integer.compare(p2[1], p1[1]);
            }
            return Integer.compare(p1[0], p2[0]);
        });

        int result = 0;

        for (int i = 0; i < n; i ++) {
            int x1 = points[i][0], y1 = points[i][1];

            int maxY = Integer.MIN_VALUE;
            // get the lower right point
            for (int j = i + 1; j < n; j ++) {
                int x2 = points[j][0], y2 = points[j][1];

                if (y2 > y1) continue;

                if (maxY < y2) {
                    maxY = y2;
                    result += 1;
                }
            }
        }

        return result;
    }
}