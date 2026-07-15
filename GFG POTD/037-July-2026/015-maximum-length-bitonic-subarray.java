// https://www.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1/




class Solution {
    public int bitonic(int[] arr) {
        int n = arr.length;
        int curr = 1;
        int maxi = curr;
        int currEqual = 1;
        boolean isDec = false;
        for (int i = 1; i < n; i ++) {
            curr ++;
            if (arr[i - 1] < arr[i]) {
                if (isDec == true) {
                    curr = Math.max(2, currEqual + 1);
                    isDec = false;
                }
            } else if (arr[i - 1] > arr[i]) {
                isDec = true;
            }
            if (arr[i - 1] == arr[i]) currEqual += 1;
            else currEqual = 1;
            maxi = Math.max(maxi, curr);
        }
        return maxi;
    }
}