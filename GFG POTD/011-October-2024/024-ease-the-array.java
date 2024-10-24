// https://www.geeksforgeeks.org/problems/ease-the-array0633/1



//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    // TC : O(N)
    // SC : O(N)
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            ArrayList<Integer> array1 = new ArrayList<Integer>();
            String line = read.readLine();
            String[] tokens = line.split(" ");
            for (String token : tokens) {
                array1.add(Integer.parseInt(token));
            }
            ArrayList<Integer> v = new ArrayList<Integer>();
            int[] arr = new int[array1.size()];
            int idx = 0;
            for (int i : array1) arr[idx++] = i;

            v = new Solution().modifyAndRearrangeArr(arr);

            for (int i = 0; i < v.size(); i++) System.out.print(v.get(i) + " ");

            System.out.println();
        
            System.out.println("~");
        }
    }
}

// } Driver Code Ends

// User function Template for Java
class Solution {
    static ArrayList<Integer> modifyAndRearrangeArr(int arr[]) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>();
        int cntZero = 0;
        for (int i = 1; i < n; i ++) {
            if (arr[i] != 0 && arr[i] == arr[i - 1]) {
                cntZero ++;
                res.add(2 * arr[i]);
                i ++;
            } else {
                if (arr[i - 1] != 0) {
                    res.add(arr[i - 1]);
                } else {
                    cntZero ++;
                }
                
                if (i + 1 == n && arr[i] != 0) {
                    res.add(arr[i]);
                } else if (i + 1 == n) {
                    cntZero ++;
                }
            }
        }
        while (cntZero -- > 0) {
            res.add(0);
        }
        return res;
    }
}