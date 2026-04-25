// https://www.geeksforgeeks.org/problems/asteroid-collision/1/




import java.util.*;

class Solution {
    public ArrayList<Integer> reducePairs(int[] arr) {
        ArrayList<Integer> stk = new ArrayList<>();
        
        for (int ele : arr) {
            boolean destroy = false;
            
            while (!stk.isEmpty() && (ele * stk.get(stk.size() - 1) < 0)) {
                int top = stk.get(stk.size() - 1);
                
                if (Math.abs(top) > Math.abs(ele)) {
                    destroy = true;
                    break;
                } else if (Math.abs(top) < Math.abs(ele)) {
                    stk.remove(stk.size() - 1);
                } else {
                    stk.remove(stk.size() - 1);
                    destroy = true;
                    break;
                }
            }
            
            if (!destroy) stk.add(ele);
        }
        
        return stk;
    }
}