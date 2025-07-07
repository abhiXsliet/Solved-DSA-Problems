// https://www.geeksforgeeks.org/problems/next-greater-element/1




import java.util.*;

class Solution {
    public ArrayList<Integer> nextLargerElement(int[] arr) {
        int n = arr.length;
        
        Stack<Integer> stk = new Stack<>();
        ArrayList<Integer> result = new ArrayList<>(Collections.nCopies(n, -1));
        int len = 2 * n;
        
        for (int i = len - 1; i >= 0; i --) {
            while (!stk.isEmpty() && arr[stk.peek() % n] <= arr[i % n]) {
                stk.pop();
            }
            if (!stk.isEmpty()) result.set(i % n, arr[stk.peek() % n]);
            stk.add(i);
        }
        
        return result;
    }
}