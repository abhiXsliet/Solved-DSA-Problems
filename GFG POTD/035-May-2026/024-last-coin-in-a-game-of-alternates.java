// https://www.geeksforgeeks.org/problems/last-coin-in-a-game-of-alternates/1/




class Solution {
    public int coin(int[] arr) {
        int n = arr.length;
        int i = 0, j = n - 1;
        while (i < j) {
            if (arr[i] > arr[j]) i ++;
            else j --;
        }
        return arr[i];
    }
}