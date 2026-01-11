// https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1/

class Solution {
    public String minWindow(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int minLen = Integer.MAX_VALUE;
        String ans = "";

        int i = 0;
        while (i < n) {
            int j = 0;

            // forward scan
            while (i < n) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    j++;
                    if (j == m) break;
                }
                i++;
            }

            if (j < m) break; // no more subsequence possible

            // backward shrink
            int end = i;
            j = m - 1;
            while (i >= 0) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    j--;
                    if (j < 0) break;
                }
                i--;
            }

            int start = i;
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                ans = s1.substring(start, end + 1);
            }

            // reset for next search
            i = start + 1;
        }

        return ans;
    }
}