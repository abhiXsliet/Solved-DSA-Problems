// https://www.geeksforgeeks.org/problems/check-if-subtree/1https://www.geeksforgeeks.org/problems/check-if-subtree/1/





import java.util.*;
/*
Definition for Node */
class Node {
    int data;
    Node left;
    Node right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}

class Solution {
    void serialize(Node root, StringBuilder sb) {
        if (root == null) {
            sb.append("N,");
            return;
        }
        
        sb.append(root.data).append(",");
        
        serialize(root.left, sb);
        serialize(root.right, sb);
    }
    
    private ArrayList<Integer> getLPS(String pat) {
        int n = pat.length();
        
        ArrayList<Integer> LPS = new ArrayList<>(Collections.nCopies(n, 0));
        
        for (int i = 1; i < n; i ++) {
            int j = LPS.get(i - 1);
            
            while (j > 0 && pat.charAt(i) != pat.charAt(j)) {
                j = LPS.get(j - 1);
            }
            
            if (pat.charAt(i) == pat.charAt(j)) j ++;
            LPS.set(i, j);
        }
        
        return LPS;
    }
    
    private boolean KMP(String txt, String pat) {
        ArrayList<Integer> LPS = getLPS(pat);
        
        int i = 0, j = 0;
        
        while (i < txt.length()) {
            if (txt.charAt(i) == pat.charAt(j)) {
                i ++;
                j ++;
            } else {
                if (j != 0) j = LPS.get(j - 1);
                else i ++;
            }
            
            if (j == pat.length()) {
                return true;
            }
        }
        
        return false;
    }
    
    private boolean check(Node r1, Node r2) {
        if (r1 == null && r2 == null) return true;
        if (r1 == null || r2 == null) return false;
        if (r1.data != r2.data) return false;
        
        return check(r1.left, r2.left) && check(r1.right, r2.right);
    }
    
    // TC : O(N * M)
    // SC : O(H)
    private boolean brute(Node r1, Node r2) {
        if (r2 == null) return true;
        if (r1 == null) return false;
        
        if (check(r1, r2)) return true;
        
        return brute(r1.left, r2) || brute(r1.right, r2);
    }
    
    // TC : O(N + M)
    // SC : O(N + M)
    private boolean optimal(Node r1, Node r2) {
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        
        serialize(r1, s1);
        serialize(r2, s2);
        
        return KMP(s1.toString(), s2.toString());
    }
    public boolean isSubTree(Node root1, Node root2) {
        // return brute(root1, root2); 
        return optimal(root1, root2);
    }
}