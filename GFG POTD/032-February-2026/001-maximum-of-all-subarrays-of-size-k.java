// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        int n = arr.length;
        Deque<Integer> dq = new ArrayDeque<>();
        ArrayList<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        while (j < n) {
            while (!dq.isEmpty() && arr[dq.peekLast()] <= arr[j]) {
                dq.removeLast();
            }
            dq.addLast(j);
            if (j - i + 1 == k) {
                result.add(arr[dq.peekFirst()]);
                if (!dq.isEmpty() && dq.peekFirst() == i) 
                    dq.removeFirst();
                i ++;
            }
            j ++;
        }
        return result;
    }
}