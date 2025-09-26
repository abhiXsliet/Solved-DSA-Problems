// https://www.geeksforgeeks.org/problems/rotate-deque-by-k/1/




import java.util.*;

class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        while (k -- > 0) {
            if (type == 1) {
                Integer val = dq.pollLast();
                if (val != null) {
                    dq.addFirst(val);
                }
            } else {
                Integer val = dq.pollFirst();
                if (val != null) {
                    dq.addLast(val);
                }
            }
        }
    }
}