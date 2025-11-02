// https://www.geeksforgeeks.org/problems/max-dag-edges/1/




class Solution {
    public int maxEdgesToAdd(int V, int[][] edges) {
        int E = edges.length;
        int totalPossible = V * (V - 1) / 2;
        return totalPossible - E;
    }
}