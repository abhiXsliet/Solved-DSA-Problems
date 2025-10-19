// https://www.geeksforgeeks.org/problems/k-closest-values/1/




import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
    // TC : O(N*log(N))
    // SC : O(N)
    public ArrayList<Integer> getKClosest(Node root, int target, int k) {
        Comparator<Pair> cmp = (a, b) -> {
            if (a.diff == b.diff) return Integer.compare(a.val, b.val);
            return Integer.compare(a.diff, b.diff);
        };
        PriorityQueue<Pair> pq = new PriorityQueue<>(cmp);
        
        solve(root, target, pq);
        
        ArrayList<Integer> result = new ArrayList<>();
        while (!pq.isEmpty() && k -- > 0) {
            result.add(pq.poll().val);
        }
        return result;
    }
    
    private static void solve(Node root, int tar, PriorityQueue<Pair> pq) {
        if (root == null) return;
        
        solve(root.left, tar, pq);
        
        pq.offer(new Pair(Math.abs(root.data - tar), root.data));
        
        solve(root.right, tar, pq);
    }
    
    private static class Pair {
        int diff, val;
        Pair(int diff, int val) {
            this.diff = diff;
            this.val  = val;
        }
    }
}