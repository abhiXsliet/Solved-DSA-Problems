// https://leetcode.com/problems/bitwise-ors-of-subarrays/




import java.util.*;

class Solution {
    // TC : O(N * 32)
    // SC : O(N)
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> prev = new HashSet<>();
        Set<Integer> res  = new HashSet<>();

        for (int num : arr) {
            Set<Integer> curr = new HashSet<>();
            for (int val : prev) {
                curr.add(num | val);
                res.add(num | val);
            }
            res.add(num);
            curr.add(num);
            prev = curr;
        }

        return res.size();
    }
}