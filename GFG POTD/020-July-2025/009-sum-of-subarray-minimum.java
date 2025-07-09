// https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int sumSubMins(int[] arr) {
        int n = arr.length;
        
        int[] nsl = getNextSmallestLeft(arr, n);
        int[] nsr = getNextSmallestRight(arr, n);
        
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            int left  = (i - nsl[i]);
            int right = (nsr[i] - i);
            
            ans += (arr[i] * (left * right));
        }
        return ans;
    }
    
    private int[] getNextSmallestLeft(int[] arr, int n) {
        int[] nsl = new int[n];
        for (int i = 0; i < n; i ++) {
            nsl[i] = -1;
        }
        
        Stack<Integer> stk = new Stack<>();
        
        for (int i = 0; i < n; i ++) {
            while (!stk.isEmpty() && arr[stk.peek()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) nsl[i] = stk.peek();
            stk.add(i);
        }
        
        return nsl;
    }

    private int[] getNextSmallestRight(int[] arr, int n) {
        int[] nsr = new int[n];
        for (int i = 0; i < n; i ++) {
            nsr[i] = n;
        }
        
        Stack<Integer> stk = new Stack<>();
        
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.isEmpty() && arr[stk.peek()] > arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) nsr[i] = stk.peek();
            stk.add(i);
        }
        
        return nsr;
    }
}