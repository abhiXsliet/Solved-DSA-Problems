// https://www.geeksforgeeks.org/problems/killing-spree3020/1/




import java.util.*;

class Solution {
    private boolean isPossible(int tar, int p) {
        long sum = (1L * tar * (tar + 1) * (2 * tar + 1));
        sum /= 6;
        return sum <= p;
    }
    private void solve(List<Integer> store, int p) {
        long sum = 0;
        for (int i = 1; i < Math.sqrt(p); i ++) {
            long val = (i * i);
            sum += val;
            if (sum > p) break;
            store.add((int) val);
        }
    }
    
    private int approach_1(int p) {
        List<Integer> store = new ArrayList<>();
        solve(store, p);
        
        int maxDef = 0;
        for (int i = 0; i < store.size(); i ++) {
            if (p < store.get(i)) break;
            p -= store.get(i);
            maxDef += 1;
        }
        return maxDef;
    }
    
    private int approach_2(int p) {
        int low = 1;
        int high = (int) Math.sqrt(p);
        int res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, p)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
    int maxPeopleDefeated(int p) {
        // return approach_1(p);
        return approach_2(p);
    }
};