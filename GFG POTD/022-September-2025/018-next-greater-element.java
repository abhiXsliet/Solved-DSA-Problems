// https://www.geeksforgeeks.org/problems/next-greater-element/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public ArrayList<Integer> nextGreater(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> result = new ArrayList(n);
        for (int i = 0; i < n; i ++) result.add(-1);
        
        Stack<Integer> stk = new Stack<>();
        
        for (int i = 2 * n - 1; i >= 0; i --) {
            while (!stk.isEmpty() && stk.peek() <= arr[i % n]) {
                stk.pop();
            }
            result.set(i % n, (stk.isEmpty() ? -1 : stk.peek()));
            stk.push(arr[i % n]);
        }
        return result;
    }
}