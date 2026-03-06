// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/




class Solution {
    private int solve_approach_1(String s) {
        int n = s.length();
        
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {   // first possible seq. : 010101...
                if (s.charAt(i) != '0') cnt1++;
            }
            else {
                if (s.charAt(i) != '1') cnt1++;
            }

            if (i % 2 == 0) {   // second possible seq. : 101010...
                if (s.charAt(i) != '1') cnt2++;
            }
            else {
                if (s.charAt(i) != '0') cnt2++;
            }
        }

        return Math.min(cnt1, cnt2);
    }
    public int minOperations(String s) {
        return solve_approach_1(s);
    }
}