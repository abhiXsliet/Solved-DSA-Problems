// https://www.geeksforgeeks.org/problems/count-frequency-of-an-element-in-a-given-range/1/




import java.util.*;

class Solution {
    private int lowerBound(ArrayList<Integer> pos, int l) {
        int n = pos.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (pos.get(mid) < l) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
    private int upperBound(ArrayList<Integer> pos, int r) {
        int n = pos.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (pos.get(mid) > r) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    public ArrayList<Integer> freqInRange(int[] arr, int[][] queries) {
        int n = arr.length;
        int q = queries.length;
        
        HashMap<Integer, ArrayList<Integer>> mpp = new HashMap<>();
        
        for (int i = 0; i < n; i ++) {
            mpp.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < q; i ++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            
            if (!mpp.containsKey(x)) {
                result.add(0);
                continue;
            }
            
            ArrayList<Integer> pos = mpp.get(x);
            
            int lower = lowerBound(pos, l);
            int upper = upperBound(pos, r);
            
            result.add(upper - lower);
        }
        return result;
    }
}