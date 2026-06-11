// https://www.geeksforgeeks.org/problems/find-equal-point-in-string-of-brackets2542/1/




class Solution {
    public int findIndex(String s) {
        int n = s.length();

        int close = 0;
        for (char ch : s.toCharArray()) {
            if (ch == ')')
                close++;
        }

        int open = 0;

        for (int i = 0; i < n; i++) {

            if (open == close)
                return i;

            if (s.charAt(i) == '(')
                open++;
            else
                close--;
        }

        return n;
    }
}