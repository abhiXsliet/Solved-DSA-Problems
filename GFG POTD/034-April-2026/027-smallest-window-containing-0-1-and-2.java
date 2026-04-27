// https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1/




class Solution {
    private boolean check(int[] store) {
        int n = store.length;
        for (int i = 0; i < n; i ++) {
            if (store[i] == 0) return false;
        }
        return true;
    }
    
    public int smallestSubstring(String s) {
        int n = s.length();
        int[] store = new int[3];

        int i = 0, j = 0;
        int minLen = Integer.MAX_VALUE;
        
        while (j < n) {
            store[s.charAt(j) - '0'] ++;
            while (i < j && check(store)) {
                minLen = Math.min(minLen, j - i + 1);
                store[s.charAt(i) - '0'] --;
                i ++;
            }
            j ++;
        }
        
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
};
