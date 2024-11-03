// https://leetcode.com/problems/rotate-string/

class Solution {
    // TC : O(M + N)
    // SC : O(M)
    public boolean rotateString(String s, String goal) {
        int m = s.length(), n = goal.length();
        if (m != n) return false;

        String newS = s + s;
        int[] LPS = new int[newS.length()];
        getLPS(LPS, newS);

        int i = 0, j = 0;   // i for newS & j for goal
        while (i < newS.length()) {
            if (newS.charAt(i) == goal.charAt(j)) {
                i ++;
                j ++;
            } else {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i ++;
                }
            }
            if (j == n) return true;
        }
        return false;
    }

    private void getLPS(int[] LPS, String str) {
        LPS[0] = 0; // for the 1st char there is no common prefix 
        for (int i = 1; i < str.length(); i ++) {
            int j = LPS[i - 1];

            while (j > 0 && str.charAt(i) != str.charAt(j))
                j = LPS[j - 1];

            if (str.charAt(i) == str.charAt(j)) j ++;
            LPS[i] = j;
        }
    }
}