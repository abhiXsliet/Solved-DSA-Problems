// https://www.geeksforgeeks.org/problems/and-operation5726/1/




class Solution {
    // TC : O(log(l))
    public int andInRange(int l, int r) {
        int cntShifts = 0;
        while (l < r) {
            l >>= 1;
            r >>= 1;
            cntShifts += 1;
        }
        return l << cntShifts;
    }
}