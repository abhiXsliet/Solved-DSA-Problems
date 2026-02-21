// https://www.geeksforgeeks.org/problems/find-h-index--165609/1/




import java.util.*;

class Solution {
    public int hIndex(int[] citations) {
        // return approach_1(citations);
        return approach_2(citations);
    }
    private static int approach_2(int[] citations) {
        int maxi = Arrays.stream(citations).max().getAsInt();
        int[] suffix = new int[maxi + 1];
        
        for (int c : citations) suffix[c] += 1;
        
        for (int i = maxi - 1; i >= 0; i --) {
            suffix[i] += suffix[i + 1];
        }

        int hIndx = -1;
        for (int i = maxi; i >= 0; i --) {
            if (suffix[i] >= i) {
                hIndx = i;
                break;
            }
        }
        return hIndx;
    }
    private static int approach_1(int[] citations) {
        int maxi = Arrays.stream(citations).max().getAsInt();

        int low = 0, high = maxi;
        int ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(citations, mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
    private static boolean isPossible(int[] cit, int tar) {
        int cntPaper = 0;
        for (int c : cit) {
            if (c >= tar) cntPaper += 1;
        }
        return cntPaper >= tar;
    }
}