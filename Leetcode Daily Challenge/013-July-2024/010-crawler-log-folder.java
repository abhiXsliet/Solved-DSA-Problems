// https://leetcode.com/problems/crawler-log-folder/



import java.util.*;

class Solution {
    public int minOperations(String[] logs) {
        // return approach_1(logs);     // Brute
        // return approach_2(logs);     // Better
        // return approach_3(logs);     // Better : Different writing style
        return approach_4(logs);        // Using Stack
    }

    // TC : O(M) Where M = logs array size
    // SC : O(N) Where N = Length of Individual Strings
    static private int approach_4(String[] logs) {
        Stack<String> stk = new Stack<>();
        for (String log : logs) {
            if (!log.equals("../") && !log.equals("./"))
                stk.push(log);
            else if (log.equals("../"))
                if (!stk.empty()) stk.pop();
        }
        return stk.size();
    }

    // TC : O(M) Where M = logs array size
    // SC : O(1)
    static private int approach_3(String[] logs) {
        int depth = 0;
        for (String log : logs) {
            if (log.equals("../"))
                depth = Math.max(0, depth - 1);
            else if (log.equals("./")) 
                continue;
            else depth ++;
        }
        return depth;
    }

    // TC : O(M) Where M = logs array size
    // SC : O(1)
    static private int approach_2(String[] logs) {
        int depth = 0;
        for (String log : logs) {
            int n   = log.length();
            int dot = 0;
            if (log.charAt(n - 2) >= '0' && log.charAt(n - 2) <= '9' ||
                log.charAt(n - 2) >= 'a' && log.charAt(n - 2) <= 'z') {
                depth += 1;
            }
            if (log.charAt(0) == '.' && log.charAt(n - 2) == '.') {
                dot = (n - 2); 
            }
            depth = depth >= dot ? depth - dot : 0;
        }
        return depth;
    }

    // TC : O(M*N) Where M = logs array size & N = Max Length of Individual String
    // SC : O(1)
    static private int approach_1(String[] logs) {
        int depth = 0;
        for (String log : logs) {
            int n   = log.length();
            int dot = 0;
            for (int i = n - 2; i >= 0; i --) {
                if (log.charAt(i) >= '0' && log.charAt(i) <= '9' ||
                    log.charAt(i) >= 'a' && log.charAt(i) <= 'z') {
                    depth += 1;
                    break;
                }
                if (i - 1 >= 0 && log.charAt(i - 1) == '.') {
                    dot += 1; 
                }
            }
            depth = depth >= dot ? depth - dot : 0;
        }
        return depth;
    }
}