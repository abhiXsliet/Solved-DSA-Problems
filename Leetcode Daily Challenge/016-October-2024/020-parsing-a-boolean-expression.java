// https://leetcode.com/problems/parsing-a-boolean-expression/


import java.util.*;

class Solution {
    public boolean parseBoolExpr(String expression) {
        Stack<Character> stk = new Stack<>();

        for (char ch : expression.toCharArray()) {
            if (ch == ',') continue;

            if (ch == ')') {
                ArrayList<Character> vec = new ArrayList<>();

                while (stk.peek() != '(') {
                    char topCh = stk.peek();
                    stk.pop();
                    vec.add(topCh);
                }

                stk.pop();  // '('
                
                char op = stk.peek();    // '!', '|', '&'
                stk.pop();
                
                char getAnswer = solveOperator(vec, op);
                stk.push(getAnswer);
            } else {
                stk.push(ch);
            }
        }
        return stk.peek() != 'f';
    }

    private char solveOperator(ArrayList<Character> arr, char op) {
        if (op == '!') {
            return arr.get(0) == 'f' ? 't' : 'f';
        }

        if (op == '&') {
            for (char ch : arr) {
                if (ch == 'f') return 'f';
            }
            return 't';
        }

        // '|'
        for (char ch : arr) {
            if (ch == 't') return 't';
        }
        return 'f';
    }
}