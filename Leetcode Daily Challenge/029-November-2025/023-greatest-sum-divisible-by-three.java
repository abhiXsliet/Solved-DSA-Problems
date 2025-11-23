// https://leetcode.com/problems/greatest-sum-divisible-by-three/


import java.util.*;

class Solution {
    public int maxSumDivThree(int[] nums) {
        int sum = 0;
        List<Integer> r1 = new ArrayList<>();
        List<Integer> r2 = new ArrayList<>();

        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) r1.add(x);
            else if (x % 3 == 2) r2.add(x);
        }

        Collections.sort(r1);
        Collections.sort(r2);

        if (sum % 3 == 0) return sum;

        int ans = 0;

        if (sum % 3 == 1) {
            int opt1 = r1.size() > 0 ? sum - r1.get(0) : 0;
            int opt2 = r2.size() > 1 ? sum - (r2.get(0) + r2.get(1)) : 0;
            ans = Math.max(opt1, opt2);
        } 
        else { // sum % 3 == 2
            int opt1 = r2.size() > 0 ? sum - r2.get(0) : 0;
            int opt2 = r1.size() > 1 ? sum - (r1.get(0) + r1.get(1)) : 0;
            ans = Math.max(opt1, opt2);
        }

        return ans;
    }
}