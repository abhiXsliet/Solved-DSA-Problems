// https://www.geeksforgeeks.org/problems/lcm-triplet1501/1


class Solution {
    int lcmTriplets(int n) {
        if (n == 1 || n == 2) return n;
        long maxLcm = 0;
        for (int i = n; i >= n - 3; i --) {
            for (int j = i; j >= n - 3; j --) {
                for (int k = j; k >= n - 3; k --) {
                    if (i != j && j != k && i != k) {
                        long val = lcm(lcm(i, j), k);
                        maxLcm   = Math.max(maxLcm, val);
                    }
                }
            }
        }
        return (int)maxLcm;
    }
    private long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }
    private long gcd(long a, long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
}