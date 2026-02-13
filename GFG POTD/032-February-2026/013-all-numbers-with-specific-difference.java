// https://www.geeksforgeeks.org/problems/all-numbers-with-specific-difference3558/1/




class Solution {
    int digitSum(long x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    public int getCount(int n, int d) {

        for (long x = d; x <= Math.min(n, d + 100); x++) {
            if (x - digitSum(x) >= d) {
                return (int)(n - x + 1);
            }
        }

        return 0;
    }
}