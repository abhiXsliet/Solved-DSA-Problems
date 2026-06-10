// https://www.geeksforgeeks.org/problems/binary-searchable-elements/1/




class Solution {
    private void solve(int[] arr, int l, int r, int minV, int maxV, int[] res) {
        if (l > r) return;
        
        int mid = l + (r - l) / 2;
        if (arr[mid] > minV && arr[mid] < maxV) {
            res[0] += 1;
        }
        
        solve(arr, l, mid - 1, minV, Math.min(maxV, arr[mid]), res);
        solve(arr, mid + 1, r, Math.max(minV, arr[mid]), maxV, res);
    }
    // TC : O(N)
    // SC : O(log(N)) recursive space
    public int binarySearchable(int[] arr) {
        // brute force -> nlog(n)
        int n = arr.length;
        int[] res = new int[1];
        solve(arr, 0, n - 1, Integer.MIN_VALUE, Integer.MAX_VALUE, res);
        return res[0];
    }
};