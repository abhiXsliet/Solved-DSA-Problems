// https://leetcode.com/problems/maximum-average-pass-ratio/




import java.util.*;

class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<ClassInfo> pq = new PriorityQueue<>((a, b) -> 
            Double.compare(b.gain(), a.gain())
        );

        for (int[] cls : classes) {
            pq.offer(new ClassInfo(cls[0], cls[1]));
        }

        while (extraStudents -- > 0) {
            ClassInfo top = pq.poll();
            top.pass ++;
            top.total ++;
            pq.offer(top);
        }

        double totalRatio = 0.0;
        while (!pq.isEmpty()) {
            ClassInfo top = pq.poll();
            totalRatio += ((double)top.pass / top.total);
        }
        return (totalRatio / classes.length);
    }

    private static class ClassInfo {
        int pass, total;
        ClassInfo(int p, int t) {
            this.pass  = p;
            this.total = t;
        }

        double gain() {
            double before = (double) pass / total;
            double after  = (double) (pass + 1) / (total + 1);
            return (after - before);
        }
    }
}