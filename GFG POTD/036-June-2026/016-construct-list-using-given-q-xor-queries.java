// https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1/




import java.util.*;

class Solution {
    public ArrayList<Integer> constructList(int[][] queries) {
        int n = queries.length;
        ArrayList<Integer> res = new ArrayList<>();
        res.add(0);
        int xored = 0;
        for (int i = 0; i < n; i ++) {
            int q = queries[i][0];
            int v = queries[i][1];
            if (q == 0) {
                res.add(xored ^ v);
            } else {
                xored ^= v;
            }
        }
        for (int i = 0; i < res.size(); i ++) {
            res.set(i, res.get(i) ^ xored);
        }
        Collections.sort(res);
        return res;
    }
}