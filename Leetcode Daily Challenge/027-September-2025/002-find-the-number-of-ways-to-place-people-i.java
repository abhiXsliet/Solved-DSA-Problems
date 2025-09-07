// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/




import java.util.*;

class Solution {
    public int numberOfPairs(int[][] points) {
        // return approach_1(points);
        return approach_2(points);
    }

    // TC : O(N^2)
    // SC : O(1)
    private static int approach_2(int[][] points) {
        int n = points.length;
        
        Arrays.sort(points, (p1, p2) -> {
            if (p1[0] == p2[0]) {
                return Integer.compare(p2[1], p1[1]);   // descending y if x's are equal
            }
            return Integer.compare(p1[0], p2[0]);   // ascending x
        });
        
        int result = 0;

        for (int i = 0; i < n; i ++) {
            int x1 = points[i][0], y1 = points[i][1];   // consider this upper left point

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

    // TC : O(N^3)
    // SC : O(1)
    private static int approach_1(int[][] points) {
        int n = points.length;
        int result = 0;

        for (int i = 0; i < n; i ++) {
            int x1 = points[i][0], y1 = points[i][1];   // consider this upper left point

            // get the lower right point
            for (int j = 0; j < n; j ++) {

                if (j == i) continue;
                int x2 = points[j][0], y2 = points[j][1];

                if (x2 >= x1 && y2 <= y1) {

                    boolean isPtInside = false;
                    for (int k = 0; k < n; k ++) {

                        if (k == i || k == j) continue;
                        int x3 = points[k][0], y3 = points[k][1];

                        if (x3 >= x1 && x3 <= x2 && y3 >= y2 && y3 <= y1) {
                            isPtInside = true;
                            break;
                        }
                    }

                    if (!isPtInside) result += 1;
                }
            }
        }

        return result;
    }
}