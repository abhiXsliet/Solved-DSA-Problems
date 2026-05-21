// https://www.geeksforgeeks.org/problems/check-set-bits5408/1/




class Solution {
    public boolean isBitSet(int n) {
        int temp = n;
        if (temp == 0) return false;
        while (temp > 0) {
            if ((1 & temp) != 1) return false;
            temp >>= 1;
        }
        return true;
    }
};