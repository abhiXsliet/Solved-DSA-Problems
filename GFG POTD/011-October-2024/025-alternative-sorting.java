// https://www.geeksforgeeks.org/problems/alternative-sorting1311/1




//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
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

            v = new Solution().alternateSort(arr);

            for (int i = 0; i < v.size(); i++) System.out.print(v.get(i) + " ");

            System.out.println();
            System.out.println("~");
        }
    }
}
// } Driver Code Ends

// User function Template for Java
class Solution {
    // TC : O(N*log(N))
    // SC : O(N)
    public static ArrayList<Integer> alternateSort(int[] arr) {
        int size = arr.length;
        ArrayList<Integer> res = new ArrayList<>();
        Arrays.sort(arr);
        int i = size - 1;
        int j = 0;
        boolean flag = false;
        while (j <= i) {
            if (flag) {
                res.add(arr[j]);
                j ++;
            } else {
                res.add(arr[i]);
                i --;
            }
            flag = !flag;
        }
        return res;
    }
}