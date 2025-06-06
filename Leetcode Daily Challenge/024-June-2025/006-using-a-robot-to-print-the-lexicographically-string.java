// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution {
    // TC : O(N)
    // SC : O(N)
    public String robotWithString(String s) {
        int n = s.length();

        char[] minCharToRight = new char[n];
        minCharToRight[n - 1] = s.charAt(n - 1);
        for (int i = n - 2; i >= 0; i --) {
            minCharToRight[i] = (char) Math.min(minCharToRight[i + 1], s.charAt(i));
        }

        StringBuilder paper = new StringBuilder();
        StringBuilder t     = new StringBuilder();

        for (int i = 0; i < n; i ++) {
            t.append(s.charAt(i));

            char minChar = (i + 1 < n) ? minCharToRight[i + 1] : s.charAt(i);

            while (t.length() > 0 && t.charAt(t.length() - 1) <= minChar) {
                paper.append(t.charAt(t.length() - 1));
                t.deleteCharAt(t.length() - 1);
            }
        }

        while (t.length() > 0) {
            paper.append(t.charAt(t.length() - 1));
            t.deleteCharAt(t.length() - 1);
        }

        return paper.toString();
    }
}