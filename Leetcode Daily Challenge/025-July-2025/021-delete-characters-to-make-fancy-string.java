// https://leetcode.com/problems/delete-characters-to-make-fancy-string/




class Solution {
    // TC : O(N)
    // SC : O(N)
    public String makeFancyString(String s) {
        StringBuilder res = new StringBuilder();
        int cnt = 1;
        for (int i = 0; i < s.length(); i ++) {
            res.append(s.charAt(i));
            if (i > 0 && s.charAt(i) == s.charAt(i - 1)) {
                cnt += 1;
                if (cnt >= 3) {
                    res.deleteCharAt(res.length() - 1);
                }
            } else cnt = 1;
        }
        return res.toString();
    }
}