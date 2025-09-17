// https://www.geeksforgeeks.org/problems/decode-the-string2444/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    static String decodeString(String s) {
        Stack<Character> stk = new Stack<>();
        
        for (char ch : s.toCharArray()) {
            if (ch == ']') {
                // get the substring b/w [...]
                StringBuilder substr = new StringBuilder();
                while (!stk.isEmpty() && stk.peek() != '[') {
                    substr.append(stk.pop());
                }
                substr.reverse();
                
                if (!stk.isEmpty() && stk.peek() == '[') stk.pop();  // remove ']'
                
                int times = getTimes(stk);
                
                StringBuilder expanded = new StringBuilder();
                for (int i = 0; i < times; i ++) {
                    expanded.append(substr);
                }
                
                for (char c : expanded.toString().toCharArray()) {
                    stk.push(c);
                }
                
            } else {
                stk.push(ch);
            }
        }
        
        StringBuilder result = new StringBuilder();
        while (!stk.isEmpty()) {
            result.append(stk.pop());
        }
        result.reverse();
        return result.toString();
    }
    
    static private int getTimes(Stack<Character> stk) {
        int result = 0, base = 1;
        while (!stk.isEmpty() && isDigit(stk.peek())) {
            result = (stk.peek() - '0') * base + result;
            base  *= 10;
            stk.pop();
        }
        return result;
    }
    
    static private boolean isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
}