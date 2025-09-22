// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public ArrayList<Integer> maxOfMins(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> result = new ArrayList<>(Collections.nCopies(n, 0));
        
        Stack<Integer> stk = new Stack<>();
        
        for (int i = 0; i < n; i ++) {
            while (!stk.isEmpty() && arr[i] < arr[stk.peek()]) {
                int nse  = i;
                int cIdx = stk.pop(); 
                int pse  = stk.isEmpty() ? -1 : stk.peek();
                int len  = nse - pse - 2;   
                
                result.set(len, Math.max(result.get(len), arr[cIdx]));
            }
            stk.push(i);
        }
        
        while (!stk.isEmpty()) {
            int nse  = n;
            int cIdx = stk.pop();
            int pse  = stk.isEmpty() ? -1 : stk.peek();
            int len  = nse - pse - 2;
            
            result.set(len, Math.max(result.get(len), arr[cIdx]));
        }
        
        for (int i = n - 2; i >= 0; i --) {
            result.set(i, Math.max(result.get(i), result.get(i + 1)));
        }
        
        return result;
    }
}