// https://leetcode.com/problems/transform-array-to-all-equal-elements/




import java.util.*;

class Solution {
    public boolean canMakeEqual(int[] nums, int k) {
        int n = nums.length;

        List<Integer> storeNeg = new ArrayList<>();
        List<Integer> storePos = new ArrayList<>();

        for (int i = 0; i < n; i ++) {
            if (nums[i] == -1) {
                storeNeg.add(i);
            } else {
                storePos.add(i);
            }
        }

        int NegSize = storeNeg.size();
        int posSize = storePos.size();
        int cntN = 0, cntP = 0;

        for (int i = 0; i < NegSize - 1; i += 2) {
            cntN += (storeNeg.get(i + 1) - storeNeg.get(i));
        }
        for (int i = 0; i < posSize - 1; i += 2) {
            cntP += (storePos.get(i + 1) - storePos.get(i));
        }

        if (NegSize % 2 != 0 && posSize % 2 != 0) 
            return false;

        if (NegSize % 2 == 0 && posSize % 2 != 0) {
            return cntN <= k;
        } else if (NegSize % 2 != 0 && posSize % 2 == 0) {
            return cntP <= k;
        } 
        return (cntN <= k || cntP <= k);
    }
}