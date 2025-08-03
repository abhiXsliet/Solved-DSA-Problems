// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/




class Solution {
    // TC : O(K * log(N))
    // SC : O(N)
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.length;

        int[] positions = new int[n];
        int[] prefixSum = new int[n];

        for (int i = 0; i < n; i ++) {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruit = 0;
        
        for (int d = 0; d <= k/2; d ++) {
            // case - 1 : first go left then explore right with remaining steps
            int i      = startPos - d;      // going left
            int remain = k - 2 * d;         // remaining steps after going left
            int j      = startPos + remain; // going right

            int left  = lowerBound(positions, i);
            int right = upperBound(positions, j) - 1;

            if (left <= right) {
                int value  = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruit   = Math.max(maxFruit, value);
            }

            // case - 2 : first go right then explore left with the remaining steps
            j = startPos + d;       // going right
            i = startPos - remain;  // going left

            left  = lowerBound(positions, i);
            right = upperBound(positions, j) - 1; 

            if (left <= right) {
                int value  = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruit   = Math.max(maxFruit, value);
            }
        }
        
        return maxFruit;
    }
    private int lowerBound(int[] arr, int tar) {
        int n = arr.length;
        int low = 0, high = n - 1, res = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= tar) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
    private int upperBound(int[] arr, int tar) {
        int n = arr.length;
        int low = 0, high = n - 1, res = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > tar) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
}