// https://www.geeksforgeeks.org/problems/max-rope-cutting1312/1




class Solution {
    public int maxProduct(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        return ans * n;
    }
}