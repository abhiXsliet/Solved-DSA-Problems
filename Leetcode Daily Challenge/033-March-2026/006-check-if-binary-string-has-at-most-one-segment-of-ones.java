// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/




class Solution {
    public boolean checkOnesSegment(String s) {
        // return approach_1(s);
        return approach_2(s);
    }
    private boolean approach_1(String s) {
        int cnt = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '1') cnt += 1;
        }

        if (cnt == 1) return true;

        int c = 1;
        boolean flag = false;
        for (int i = 1; i < s.length(); i ++) {
            if (s.charAt(i) == '1' && s.charAt(i) == s.charAt(i - 1)) {
                c += 1;
                flag = true;
            } else if (flag == true) break;
        }
        return cnt == c;
    }
    private boolean approach_2(String s) {
        return !s.contains("01");
    }
}