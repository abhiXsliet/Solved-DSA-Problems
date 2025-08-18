// https://www.geeksforgeeks.org/problems/find-h-index--165609/1




import java.util.*;

class Solution {
    public int hIndex(int[] citations) {
        // return approach_1(citations);
        return approach_2(citations);
    }
    
    // TC : O(N)
    // SC : O(N)
    private int approach_2(int[] citations) {
        int n = citations.length;
        
        int[] citationSum = new int[n + 1];
        for (int val : citations) {
            if (val <= n) {
                citationSum[val] += 1;
            } else {
                citationSum[n] += 1;
            }
        }
        
        int hIndex = 0;
        for (int i = n; i >= 0; i --) {
            citationSum[i] += (i == n) ? 0 : citationSum[i + 1];
            if (citationSum[i] >= i) {
                hIndex = i;
                break;
            }
        }
        return hIndex;
    }
    
    // TC : O(N * log(N))
    // SC : O(1)
    private int approach_1(int[] citations) {
        int n = citations.length;
        int low = 0, high = Arrays.stream(citations).max().getAsInt();
        int ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(citations, n, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    // is it possible to make tar as h-index whose cnt >= tar
    private boolean isPossible(int[] citations, int n, int tar) {
        int count = 0;
        for (int val : citations) {
            if (val >= tar) {
                count += 1;
            }
        }
        return count >= tar;
    }
}