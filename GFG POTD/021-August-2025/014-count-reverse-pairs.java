// https://www.geeksforgeeks.org/problems/count-reverse-pairs/1




class Solution {
    public int countRevPairs(int[] arr) {
        int n = arr.length;
        return mergeSort(arr, 0, n - 1);
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    private int mergeSort(int[] arr, int low, int high) {
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        int cnt = mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        
        return cnt;
    }
    
    private int merge(int[] arr, int low, int mid, int high) {
        int cntRev = 0;
        
        // 1. Counting reverse pairs
        int p2 = mid + 1;
        for (int p1 = low; p1 <= mid; p1 ++) {
            while (p2 <= high && (long)arr[p1] > (long) 2 * arr[p2]) p2 ++;
            cntRev += (p2 - (mid + 1));
        }
        
        // 2. performing merge operation
        int n1 = mid - low + 1, n2 = high - mid;
        int[] left  = new int[n1];
        int[] right = new int[n2];
        
        int i = 0, j = 0, k = low;
        while (i < n1) left[i ++] = arr[k ++];
        
        k = mid + 1;
        while (j < n2) right[j ++] = arr[k ++];
        
        i = 0;
        j = 0;
        k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k ++] = left[i ++];
            } else {
                arr[k ++] = right[j ++];
            }
        }
        
        while (i < n1) arr[k ++] = left[i ++];
        while (j < n2) arr[k ++] = right[j ++];
        
        return cntRev;
    }
}