// https://www.geeksforgeeks.org/problems/combination-sum-iii--111703/1/




import java.util.*;

class Solution {
    // TC : O(N * 2^9)
    // SC : O(N)
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        solve(n, k, 1, 0, temp, result);
        return result;
    }
    
    private static void solve(int n, int k, int start, int sum, ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> result) {
        if (k == 0 || sum >= n) {
            if (k == 0 && sum == n) result.add(new ArrayList<>(temp));
            return;
        }
        
        for (int val = start; val <= 9; val ++) {
            temp.add(val);
            solve(n, k - 1, val + 1, sum + val, temp, result);
            temp.remove(temp.size() - 1);
        }
    }
}