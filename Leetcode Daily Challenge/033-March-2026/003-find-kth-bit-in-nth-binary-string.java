// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/




import java.util.*;

class Solution {
    public char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int len = (1 << n) - 1;

        if (k == (int)Math.ceil(len / 2.0)) {
            return '1';
        } else if (k < (int)Math.ceil(len / 2.0)) {
            return findKthBit(n - 1, k);
        }
        char ch = findKthBit(n - 1, len - (k - 1));
        return (ch == '0') ? '1' : '0';
    }
}