// https://www.geeksforgeeks.org/problems/longest-subarray-length--202010/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public static int longestSubarray(int[] arr) {
        int n = arr.length;
        
        int[] nge = getNge(arr);
        int[] pge = getPge(arr);
        
        int maxLen = 0;
        for (int i = 0; i < n; i ++) {
            int len = (nge[i] - pge[i] - 1);
            if (arr[i] <= len) {
                maxLen = Math.max(maxLen, len);
            }
        }
        return maxLen;
    }
    
    // TC : O(N)
    // SC : O(1)
    private static int[] getNge(int[] arr) {
        int n = arr.length;
        Stack<Integer> stk = new Stack<>();
        int[] result = new int[n];
        Arrays.fill(result, n);
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.isEmpty() && arr[stk.peek()] <= arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) result[i] = stk.peek();
            stk.push(i);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    private static int[] getPge(int[] arr) {
        int n = arr.length;
        Stack<Integer> stk = new Stack<>();
        int[] result = new int[n];
        Arrays.fill(result, -1);
        for (int i = 0; i < n; i ++) {
            while (!stk.isEmpty() && arr[stk.peek()] <= arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) result[i] = stk.peek();
            stk.push(i);
        }
        return result;
    }
}