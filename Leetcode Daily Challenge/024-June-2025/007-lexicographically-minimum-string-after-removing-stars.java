// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/




import java.util.*;

class Solution {
    // TC : O(N log N)
    // SC : O(N)
    public String clearStars(String s) {
        int n = s.length();

        char[] chars = s.toCharArray();

        // custom comparator for priority queue
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>(
            (p1, p2) -> {
                if (p1.getKey().equals(p2.getKey())) {
                    return Integer.compare(p2.getValue(), p1.getValue());   // higher index first
                }
                return Character.compare(p1.getKey(), p2.getKey()); // lex char first
            }
        );

        for (int i = 0; i < n; i ++) {
            if (chars[i] != '*') {
                pq.offer(new AbstractMap.SimpleEntry<>(chars[i], i));
            } else if (!pq.isEmpty()) {
                int idx = pq.poll().getValue();
                chars[idx] = '*';
            }
        }

        StringBuilder res = new StringBuilder();
        for (char ch : chars) {
            if (ch != '*') {
                res.append(ch);
            }
        }
        return res.toString();
    }
}