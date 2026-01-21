// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/




import java.util.*;

class Solution {
    class Pair {
        int value;
        int count;
        Pair(int value, int count) {
            this.value = value;
            this.count = count;
        }
    }
    
    // TC : O(N)
    // SC : O(N)
    public ArrayList<Integer> calculateSpan(int[] arr) {
        int n = arr.length;
        
        Stack<Pair> stk = new Stack<>();
        ArrayList<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < n; i ++) {
            int cnt = 1;
            while (!stk.isEmpty() && stk.peek().value <= arr[i]) {
                cnt += stk.pop().count;
            }
            result.add(cnt);
            stk.push(new Pair(arr[i], cnt));
        }
        
        return result;
    }
}