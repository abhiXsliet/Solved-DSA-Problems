// https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1/




import java.util.*;

class Solution {
    public static ArrayList<Integer> increasingNumbers(int n) {
        ArrayList<Integer> result = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        if (n == 1) {
            for (int val = 0; val <= 9; val ++) 
                result.add(val);
            return result;
        }
        solve(n, result, temp);
        return result;
    }
    
    private static void solve(int n, ArrayList<Integer> result, ArrayList<Integer> temp) {
        if (n == 0) {
            int ans = 0;
            for (int v : temp) ans = ans * 10 + v;
            result.add(ans);
            return;
        }
        
        for (int val = 1; val <= 9; val ++) {
            if (temp.isEmpty() || temp.get(temp.size() - 1) < val) {
                temp.add(val);
                solve(n - 1, result, temp);
                temp.remove(temp.size() - 1);
            }
        }
    }
}
