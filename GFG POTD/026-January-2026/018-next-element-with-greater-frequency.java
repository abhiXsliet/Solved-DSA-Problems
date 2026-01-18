// https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1/




import java.util.*;

class Solution {
    public ArrayList<Integer> nextFreqGreater(int[] arr) {
        int n = arr.length;
        
        Map<Integer, Integer> mpp = new HashMap<>();
        for (int num : arr) {
            mpp.put(num, mpp.getOrDefault(num, 0) + 1);
        }
        
        Stack<Integer> stk = new Stack<>();
        
        ArrayList<Integer> result = new ArrayList<>(Collections.nCopies(n, -1));
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.isEmpty() && mpp.get(stk.peek()) <= mpp.get(arr[i])) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                result.set(i, stk.peek());
            }
            stk.push(arr[i]);
        }
        return result;
    }
}