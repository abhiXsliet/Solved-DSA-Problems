// https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1




import java.util.AbstractMap.SimpleEntry;
import java.util.Stack;

class Solution {
    public int findLength(int[] color, int[] radius) {
        int n = color.length;
        Stack<SimpleEntry<Integer, Integer>> stk = new Stack<>();
        for (int i = 0; i < n; i ++) {
            if (!stk.isEmpty() && stk.peek().getKey().equals(color[i]) && stk.peek().getValue().equals(radius[i])) {
                stk.pop();
            } else {
                stk.push(new SimpleEntry<>(color[i], radius[i]));
            }
        }
        return stk.size();
    }
}