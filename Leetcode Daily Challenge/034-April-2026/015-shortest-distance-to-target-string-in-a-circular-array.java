// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/




class Solution {
    public int approach_1(String[] words, String target, int startIndex) {
        int n = words.length;

        int minD = Integer.MAX_VALUE;
        for (int i = startIndex; i < n + startIndex; i ++) {
            int steps = i - startIndex;

            // forward
            int idx1 = i % n;

            // backward (FIXED)
            int idx2 = (startIndex - steps + n) % n;

            if (words[idx1].equals(target)) {
                minD = Math.min(minD, steps);
            }

            if (words[idx2].equals(target)) {
                minD = Math.min(minD, steps);
            }
        }
        return minD == Integer.MAX_VALUE ? -1 : minD;
    }
    public int approach_2(String[] words, String target, int startIndex) {
        int n = words.length;
        int minD = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (words[i].equals(target)) {
                int forward = (i - startIndex + n) % n;
                int backward = (startIndex - i + n) % n;

                minD = Math.min(minD, Math.min(forward, backward));
            }
        }

        return minD == Integer.MAX_VALUE ? -1 : minD;
    }
    public int closestTarget(String[] words, String target, int startIndex) {
        // return approach_1(words, target, startIndex);
        return approach_2(words, target, startIndex);
    }
}