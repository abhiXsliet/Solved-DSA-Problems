// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int evaluatePostfix(String[] arr) {
        Stack<Integer> stk = new Stack<>();
        
        for (String str : arr) {
            if (isExp(str)) {
                if (stk.size() >= 2) {
                    int ele1 = stk.pop();
                    int ele2 = stk.pop();
                    
                    if (str.charAt(0) == '+') {
                        stk.push(ele2 + ele1);
                    } else if (str.charAt(0) == '-') {
                        stk.push(ele2 - ele1);
                    } else if (str.charAt(0) == '*') {
                        stk.push(ele2 * ele1);
                    } else if (str.charAt(0) == '/') {
                        stk.push(floorDiv(ele2, ele1));
                    } else { // '^'
                        stk.push((int)Math.pow(ele2, ele1));
                    }
                }
            } else {
                stk.push(Integer.parseInt(str));
            }
        }
        
        return stk.peek();
    }

    private static int floorDiv(int a, int b) {
        int res = a / b;
        if (((a ^ b) < 0) && ((a % b) != 0)) {
            res --;
        }
        return res;
    }
    
    private static boolean isExp(String str) {
        if (str.length() > 1) return false;
        return (str.charAt(0) == '+' || str.charAt(0) == '-' || str.charAt(0) == '*' || 
                str.charAt(0) == '/' || str.charAt(0) == '^');
    }
}