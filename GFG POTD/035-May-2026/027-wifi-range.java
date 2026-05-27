// https://www.geeksforgeeks.org/problems/wifi-range--170647/1/




class Solution {
    public boolean wifiRange(String s, int x) {
        int n = s.length();
        int coveredTill = -1;
        for (int i = 0; i < n; i++) {
            // found a router
            if (s.charAt(i) == '1') {
                coveredTill = Math.max(
                    coveredTill,
                    i + x
                );
            }
            // current room not covered
            if (i > coveredTill) {
                // maybe future router can cover it?
                boolean possible = false;
                for (int j = i; j <= Math.min(n - 1, i + x); j++) {
                    if (s.charAt(j) == '1') {
                        coveredTill = j + x;
                        possible = true;
                        break;
                    }
                }
                if (!possible) return false;
            }
        }
        return true;
    }
}