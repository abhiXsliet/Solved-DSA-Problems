// https://leetcode.com/problems/find-the-winner-of-the-circular-game/



import java.util.*;

class Solution {
    public int findTheWinner(int n, int k) {
        // return solve(n, k);          // Simulation
        // return solveQ(n, k);         // Simulation Using Queue
        // return solve_josephus(n, k); // Recursive Approach Of Simulation
        return solve_rec(n, k) + 1;     // +1 to get the name of the person (i.e., idx + 1 == el)
    }
    
    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    int solve_rec(int n, int k) {
        if (n == 1) return 0;
        
        int idx = solve_rec(n - 1, k);
        idx = (idx + k) % n;    // to get the original index of element prior deletion

        return idx;
    }

    // TC : O(N)
    // SC : O(N) + O(N) = O(N)
    int solve_josephus(int n, int k) {
        List<Integer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            arr.add(i);
        }

        return func(arr, k, 0);
    }

    // TC : O(N)
    // SC : O(N) -> Recursive depth
    int func(List<Integer> arr, int k, int idx) {
        int n = arr.size();
        if (n == 1) return arr.get(0);

        int removeIdx = (idx + k - 1) % n;
        arr.remove(removeIdx);

        return func(arr, k, removeIdx);
    }

    // TC : O(N^2)
    // SC : O(N)
    int solveQ(int n, int k) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) 
            q.offer(i);

        while(q.size() > 1) {
            for (int i = 1; i < k; i++) {
                q.offer(q.poll());
            }
            q.poll();
        }
        return q.peek();
    }

    // TC : O(N^2)
    // SC : O(N)
    int solve(int n, int k) {
        List<Integer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            arr.add(i);
        }

        int i = 0;
        while (arr.size() > 1) { // O(N)
            i = (i + k - 1) % arr.size();    // index to be erased
            arr.remove(i);       // erase element at index i : O(N)
        }
        return arr.get(0);
    }
}