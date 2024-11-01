// https://leetcode.com/problems/delete-characters-to-make-fancy-string/




class Solution {
    public String makeFancyString(String s) {
        // return approach_1(s);
        return approach_2(s);
    }

    // TC : O(N^2)
    // SC : O(1)
    private String approach_1(String s) {
        String res = "";
        for (char ch : s.toCharArray()) {
            if (res.isEmpty() || res.length() < 2)
                res += ch;
            else {
                int n = res.length();
                if (res.charAt(n - 1) == res.charAt(n - 2) && res.charAt(n - 2) == ch)
                    continue;
                else res += ch;
            }
        }
        return res;
    }

    // TC : O(N)
    // SC : O(1) No extra space used
    private String approach_2(String s) {
        StringBuilder res = new StringBuilder();
        for (char ch : s.toCharArray()) {
            int n = res.length();
            if (res.length() < 2 || !(res.charAt(n - 1) == res.charAt(n - 2) && res.charAt(n - 2) == ch))
                res.append(ch);
        }
        return res.toString();
    }
}