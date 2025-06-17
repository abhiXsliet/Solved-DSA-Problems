// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/




class Solution {
    public int maxDiff(int num) {
        String a = Integer.toString(num);
        String b = Integer.toString(num);

        int idx = -1;
        for (int i = 0; i < a.length(); i ++) {
            if (a.charAt(i) != '9') {
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            char ch = a.charAt(idx);
            a = a.replace(ch, '9');
        }

        for (int i = 0; i < b.length(); i ++) {
            if (i > 0 && b.charAt(i) != b.charAt(0) && b.charAt(i) != '0') {
                char ch = b.charAt(i);
                b = b.replace(ch, '0');
                break;
            } else if (i == 0 && b.charAt(i) != '1') {
                char ch = b.charAt(i);
                b = b.replace(ch, '1');
                break;
            }
        }

        return Integer.parseInt(a) - Integer.parseInt(b);
    }
}