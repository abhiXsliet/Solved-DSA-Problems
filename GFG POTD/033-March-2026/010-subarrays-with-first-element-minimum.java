// https://www.geeksforgeeks.org/problems/subarrays-with-first-element-minimum/1/




import java.util.*;

class Solution {
    public int countSubarrays(int[] arr) {
        int n = arr.length;
        int[] nextSmallest = new int[n];
        Arrays.fill(nextSmallest, n);
        Stack<Integer> stk = new Stack<>();
        
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.isEmpty() && arr[stk.peek()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) nextSmallest[i] = stk.peek();
            stk.push(i);
        }
        
        int cntSubarray = 0;
        for (int i = 0; i < n; i ++) {
            cntSubarray += (nextSmallest[i] - i);
        }
        return cntSubarray;
    }
}