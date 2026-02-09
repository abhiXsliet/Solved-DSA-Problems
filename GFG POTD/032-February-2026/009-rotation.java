// https://www.geeksforgeeks.org/problems/rotation4723/1




class Solution {
    public int findKRotation(int arr[]) {
        int n = arr.length;
        for (int i = 1; i < n; i ++) {
            if (arr[i - 1] > arr[i]) {
                return i;
            }
        }
        return 0;
    }
}