// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/




class Solution {
    // TC : O(log(num))
    // SC : O(log(num))
    public int minMaxDifference(int num) {
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

        char chr = b.charAt(0);
        b = b.replace(chr, '0');

        return Integer.parseInt(a) - Integer.parseInt(b);
    }
}