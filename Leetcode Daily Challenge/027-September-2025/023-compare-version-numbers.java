// https://leetcode.com/problems/compare-version-numbers/




import java.util.*;

class Solution {
    public int compareVersion(String version1, String version2) {
        // return way_1(version1, version2);
        return way_2(version1, version2);
    }

    // TC : O(M + N)    // M = rev1.size(), N = rev2.size()
    // SC : O(1)    
    private static int way_2(String v1, String v2) {
        int m = v1.length(), n = v2.length();
        int val1 = 0, val2 = 0;

        for (int i = 0, j = 0; i < m || j < n; i ++, j ++) {
            while (i < m && v1.charAt(i) != '.') {
                val1 = val1 * 10 + v1.charAt(i) - '0';
                i ++;
            }
            while (j < n && v2.charAt(j) != '.') {
                val2 = val2 * 10 + v2.charAt(j) - '0';
                j ++;
            }
            if (val1 < val2) return -1;
            else if (val1 > val2) return 1;
            val1 = val2 = 0;
        }

        return 0; 
    }

    // TC : O(M + N)    // M = rev1.size(), N = rev2.size()
    // SC : O(M + N)    
    private static int way_1(String v1, String v2) {
        List<Integer> rev1 = getRevision(v1);
        List<Integer> rev2 = getRevision(v2);

        int m = rev1.size(), n = rev2.size();
        int val1 = 0, val2 = 0;

        for (int i = 0, j = 0; i < m || j < n; i ++, j ++) {
            val1 = (i < m ? rev1.get(i) : 0);
            val2 = (j < n ? rev2.get(j) : 0);

            if (val1 < val2) return -1;
            else if (val1 > val2) return 1;
        }

        return 0;
    }

    private static List<Integer> getRevision(String s) {
        List<Integer> rev = new ArrayList<>();
        String parts[] = s.split("\\.");
        for (String part : parts) {
            rev.add(Integer.parseInt(part));
        }
        return rev;
    }
}