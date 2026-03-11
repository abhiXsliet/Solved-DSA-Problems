// https://leetcode.com/problems/complement-of-base-10-integer/




class Solution {
    public int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int bitsCnt = 32 - Integer.numberOfLeadingZeros(n);
        int ans = 0;
        for (int i = 0; i < bitsCnt; i ++) {
            if ((n & (1 << i)) == 0) {
                ans += Math.pow(2, i);
            } 
        }
        return ans;
    }
}