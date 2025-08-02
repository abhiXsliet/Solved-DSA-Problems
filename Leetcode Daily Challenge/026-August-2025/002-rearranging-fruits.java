// https://leetcode.com/problems/rearranging-fruits/




import java.util.*;

class Solution {
    // TC : O(N*log(N))
    // SC : O(N)
    public long minCost(int[] basket1, int[] basket2) {
        Map<Integer, Integer> mpp = new HashMap<>();
        int minEle = Integer.MAX_VALUE;

        for (int val : basket1) {
            mpp.put(val, mpp.getOrDefault(val, 0) + 1);
            minEle = Math.min(minEle, val);
        }
        for (int val : basket2) {
            mpp.put(val, mpp.getOrDefault(val, 0) - 1);
            minEle = Math.min(minEle, val);
        }

        List<Integer> finalList = new ArrayList<>();

        for (Map.Entry<Integer, Integer> entry : mpp.entrySet()) {
            Integer key = entry.getKey();
            Integer cnt = entry.getValue();

            if (cnt == 0) continue;
            if (cnt % 2 == 1) return -1;

            for (int t = 1; t <= Math.abs(cnt) / 2; t ++) {
                finalList.add(key);
            }
        }

        Collections.sort(finalList);

        long result = 0;
        for (int i = 0; i < finalList.size() / 2; i ++) {
            result += Math.min(finalList.get(i), minEle * 2);
        }
        return result;
    }
}