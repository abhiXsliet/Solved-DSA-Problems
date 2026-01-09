// https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1/




import java.util.*;

class Solution {
    // TC : O(N*log(N))
    // SC : O(N)
    private ArrayList<Integer> approach_1(int[] arr, int x) {
        int n = arr.length;
        PriorityQueue<Integer> minH = new PriorityQueue<>((a, b) -> arr[a] - arr[b]);
        PriorityQueue<Integer> maxH = new PriorityQueue<>((a, b) -> arr[b] - arr[a]);
        
        int maxLen   = 0;
        int startIdx = 0;
        int i = 0, j = 0;
        
        while (j < n) {
            minH.add(j);
            maxH.add(j);
            
            while (Math.abs(arr[minH.peek()] - arr[maxH.peek()]) > x) {
                while (!minH.isEmpty() && minH.peek() <= i) minH.poll();
                while (!maxH.isEmpty() && maxH.peek() <= i) maxH.poll();
                i ++;
            }
            
            if (j - i + 1 > maxLen) {
                maxLen = (j - i + 1);
                startIdx = i;
            }
            j ++;
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (i = startIdx; i < startIdx + maxLen; i ++) {
            result.add(arr[i]);
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    public ArrayList<Integer> approach_2(int[] arr, int x) {
        int n = arr.length;
        Deque<Integer> minD = new ArrayDeque<>();
        Deque<Integer> maxD = new ArrayDeque<>();
        
        int maxLen   = 0;
        int startIdx = 0;
        int i = 0, j = 0;
        
        while (j < n) {
            while (!minD.isEmpty() && arr[j] <= arr[minD.peekLast()]) minD.pollLast();
            while (!maxD.isEmpty() && arr[j] >= arr[maxD.peekLast()]) maxD.pollLast();
            
            minD.add(j);
            maxD.add(j);
            
            while (Math.abs(arr[minD.peekFirst()] - arr[maxD.peekFirst()]) > x) {
                if (minD.peekFirst() == i) minD.pollFirst();
                if (maxD.peekFirst() == i) maxD.pollFirst();
                i ++;
            }
            
            if (j - i + 1 > maxLen) {
                maxLen = (j - i + 1);
                startIdx = i;
            }
            j ++;
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (i = startIdx; i < startIdx + maxLen; i ++) {
            result.add(arr[i]);
        }
        return result;
    }
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        // return approach_1(arr, x);
        return approach_2(arr, x);
    }
}