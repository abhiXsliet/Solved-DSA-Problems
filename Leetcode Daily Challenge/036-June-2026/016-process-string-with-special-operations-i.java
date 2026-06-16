// https://leetcode.com/problems/process-string-with-special-operations-i/




class Solution {
    public String processStr(String s) {
        StringBuilder res = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                if (res.length() > 0) 
                    res.deleteCharAt(res.length() - 1);
            } else if (ch == '#') {
                String temp = res.toString();
                res.append(temp);
            } else if (ch == '%') {
                res.reverse();
            } else {
                res.append(ch);
            }
        }
        return res.toString();
    }
}