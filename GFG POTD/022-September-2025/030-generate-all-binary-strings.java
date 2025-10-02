// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1/




import java.util.*;

class Solution {
    public ArrayList<String> binstr(int n) {
        ArrayList<String> result = new ArrayList<>();
        StringBuilder str = new StringBuilder();
        solve(n, str, result);
        return result;
    }
    
    private static void solve(int n, StringBuilder str, ArrayList<String> result) {
        if (n == 0) {
            result.add(str.toString());
            return;
        }
        
        str.append('0');
        solve(n - 1, str, result);
        str.deleteCharAt(str.length() - 1);
        
        str.append('1');
        solve(n - 1, str, result);
        str.deleteCharAt(str.length() - 1);
    }
}