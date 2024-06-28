// https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1



//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String input_line[] = read.readLine().trim().split("\\s+");
            int n = Integer.parseInt(input_line[0]);
            String input_line1[] = read.readLine().trim().split("\\s+");
            int[][] a = new int[n][n];
            int c = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            String ans = ob.pattern(a);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

// User function Template for Java
class Solution {
    public String pattern(int[][] mat) {
        int n = mat.length;
        // return brute(mat, n);
        // return better(mat, n);
        // return optimal(mat, n);
        return optimal_2(mat, n);
    }
    
    // TC : O(N)
    // SC : O(1)
    public static boolean isPalindrome(List<Integer> row, int n) {
        int i = 0, j = n - 1;
        while (i < j) {
            if (!row.get(i).equals(row.get(j))) {
                return false;
            }
            i ++;
            j --;
        }
        return true;
    }
    
    // TC : O(N^2)
    // SC : O(N)
    public static String brute(int[][] mat, int n) {
        for (int i = 0; i < n; i ++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j ++) {
                row.add(mat[i][j]);
            }
            if (isPalindrome(row, n)) {
                return i + " R";
            }
        } 
        
        for (int j = 0; j < n; j ++) {
            List<Integer> col = new ArrayList<>();
            for (int i = 0; i < n; i ++) {
                col.add(mat[i][j]);
            }
            
            if (isPalindrome(col, n)) {
                return j + " C";
            }
        }
        
        return "-1";
    }
    
    // TC : O(N^2)
    // SC : O(1)
    public static String better(int[][] mat, int n) {
        for (int i = 0; i < n; i ++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j ++) {
                row.add(mat[i][j]);
            }
            if (isPalindrome(row, n)) {
                return i + " R";
            }
        } 
        
        for (int j = 0; j < n; j ++) {
            boolean isPalindrome = true;
            for (int i = 0; i < n/2; i ++) {
                if (mat[i][j] != mat[n - i - 1][j]) {
                    isPalindrome = false;
                }
            }
            if (isPalindrome) {
                return j + " C";
            }
        }
        
        return "-1";
    }
    
    // TC : O(N^2)
    // SC : O(1)
    public static String optimal(int[][] mat, int n) {
        for (int i = 0; i < n; i ++) {
            boolean isPalindrome = true;
            for (int j = 0; j < n/2; j ++) {
                if (mat[i][j] != mat[i][n - j - 1]) {
                    isPalindrome = false;
                }
            }
            if (isPalindrome) {
                return i + " R";
            }
        } 
        
        for (int j = 0; j < n; j ++) {
            boolean isPalindrome = true;
            for (int i = 0; i < n/2; i ++) {
                if (mat[i][j] != mat[n - i - 1][j]) {
                    isPalindrome = false;
                }
            }
            if (isPalindrome) {
                return j + " C";
            }
        }
        
        return "-1";
    }

    // TC : O(N^2)
    // SC : O(1)
    public static String optimal_2(int[][] mat, int n) {
        // store the index of first column palindrome
        int firstColPalindromeIdx = -1; 
        
        for (int i = 0; i < n; i ++) {
            boolean isPalindromeRow = true, isPalindromeCol = true;
            for (int j = 0; j < n/2; j ++) {
                if (mat[i][j] != mat[i][n - j - 1]) // Check Palindrome : Rows
                    isPalindromeRow = false;
                    
                if (mat[j][i] != mat[n - j - 1][i]) // Check Palindrome : Cols
                    isPalindromeCol = false;
            }
            if (isPalindromeRow) 
                return i + " R";
            
            if (isPalindromeCol && firstColPalindromeIdx == -1) 
                firstColPalindromeIdx = i;
        } 
        if (firstColPalindromeIdx != -1) 
            return firstColPalindromeIdx + " C";
        return "-1";
    }
}