// https://leetcode.com/problems/maximum-69-number/




class Solution {
    public int maximum69Number (int num) {
        // return approach_1(num);
        return approach_2(num);
    }

    // TC : O(log₁₀(num))
    // SC : O(1)
    private int approach_2(int num) {
        int temp = num, idx = -1, cnt = 0;
        while (temp > 0) {
            int rem = temp % 10;
            if (rem == 6) idx = cnt;
            temp /= 10;
            cnt  += 1;
        }
        if (idx == -1) return num;
        return num + (int) (3 * Math.pow(10, idx));
    }

    // TC : O(log₁₀(num))
    // SC : O(log₁₀(num))
    private int approach_1(int num) {
        char[] chars = String.valueOf(num).toCharArray();

        for (int i = 0; i < chars.length; i ++) {
            if (chars[i] == '6') {
                chars[i] = '9';
                break;
            }
        }

        return Integer.parseInt(new String(chars));
    }
}