// https://www.geeksforgeeks.org/problems/max-absolute-difference4114/1/




class Solution {
    public int maxDiffSubArrays(int[] arr) {
        int n = arr.length;

        int[] prefMax = new int[n];
        int[] prefMin = new int[n];
        int[] suffMax = new int[n];
        int[] suffMin = new int[n];

        // Prefix Maximum
        int currMax = arr[0];
        int bestMax = arr[0];
        prefMax[0] = arr[0];

        for (int i = 1; i < n; i++) {
            currMax = Math.max(arr[i], currMax + arr[i]);
            bestMax = Math.max(bestMax, currMax);
            prefMax[i] = bestMax;
        }

        // Prefix Minimum
        int currMin = arr[0];
        int bestMin = arr[0];
        prefMin[0] = arr[0];

        for (int i = 1; i < n; i++) {
            currMin = Math.min(arr[i], currMin + arr[i]);
            bestMin = Math.min(bestMin, currMin);
            prefMin[i] = bestMin;
        }

        // Suffix Maximum
        currMax = arr[n - 1];
        bestMax = arr[n - 1];
        suffMax[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            currMax = Math.max(arr[i], currMax + arr[i]);
            bestMax = Math.max(bestMax, currMax);
            suffMax[i] = bestMax;
        }

        // Suffix Minimum
        currMin = arr[n - 1];
        bestMin = arr[n - 1];
        suffMin[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            currMin = Math.min(arr[i], currMin + arr[i]);
            bestMin = Math.min(bestMin, currMin);
            suffMin[i] = bestMin;
        }

        int ans = Integer.MIN_VALUE;

        for (int i = 0; i < n - 1; i++) {
            ans = Math.max(ans,
                    Math.abs(prefMax[i] - suffMin[i + 1]));

            ans = Math.max(ans,
                    Math.abs(prefMin[i] - suffMax[i + 1]));
        }

        return ans;
    }
}