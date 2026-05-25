// https://www.geeksforgeeks.org/problems/elements-in-the-range2834/1/




class Solution {
    public boolean checkElements(int start, int end, int[] arr) {
        int tCnt = end - start + 1;
        int cnt = 0;
        for (int val : arr) {
            if (val >= start && val <= end) {
                cnt += 1;
            }
        }
        return tCnt == cnt;
    }
}