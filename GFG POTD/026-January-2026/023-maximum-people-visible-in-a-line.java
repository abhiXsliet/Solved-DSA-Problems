// https://www.geeksforgeeks.org/problems/maximum-people-visible-in-a-line/1/




import java.util.*;

class Solution {
    private static int[] getNextGreaterEle(int arr[], int n) {
        Stack<Integer> stk = new Stack<>();
        int[] result = new int[n];
        for (int i = 0; i < n; i ++) result[i] = n;
        
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.isEmpty() && arr[stk.peek()] < arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) result[i] = stk.peek();
            stk.push(i);
        }
        
        return result;
    }
    private static int[] getPrevGreaterEle(int arr[], int n) {
        Stack<Integer> stk = new Stack<>();
        int[] result = new int[n];
        for (int i = 0; i < n; i ++) result[i] = -1;
        
        for (int i = 0; i < n; i ++) {
            while (!stk.isEmpty() && arr[stk.peek()] < arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) result[i] = stk.peek();
            stk.push(i);
        }
        
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    public int maxPeople(int[] arr) {
        int n = arr.length;
        int[] nge = getNextGreaterEle(arr, n);
        int[] pge = getPrevGreaterEle(arr, n);
        
        int maxVisiblePeople = 1;
        for (int i = 0; i < n; i ++) {
            int visiblePeople = nge[i] - pge[i] - 1;
            maxVisiblePeople = Math.max(maxVisiblePeople, visiblePeople);
        }
        return maxVisiblePeople;
    }
}