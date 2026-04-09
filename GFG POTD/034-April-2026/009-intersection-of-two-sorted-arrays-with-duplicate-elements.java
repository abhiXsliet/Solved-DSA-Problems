// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-arrays-with-duplicate-elements/1/




import java.util.*;

class Solution {
    ArrayList<Integer> intersection(int[] a, int[] b) {
        int m = a.length;
        int n = b.length;
        ArrayList<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        while (i < m && j < n) {
            while (i < m && a[i] < b[j]) i ++;
            while (i < m && j < n && b[j] < a[i]) j ++;
            if (i < m && j < n && a[i] == b[j]) {
                if (result.isEmpty() || result.get(result.size() - 1) != a[i]) {
                    result.add(a[i]);
                }
                i ++;
                j ++;
            }
        }
        return result;
    }
}