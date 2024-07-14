// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1



//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            new Solution().segregate0and1(arr);
            for (int i = 0; i < array.size(); i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends

// User function Template for Java
class Solution {
    void segregate0and1(int[] arr) {
        int n = arr.length;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            while (i < j && arr[i] == 0) i ++;
            while (i < j && arr[j] == 1) j --;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}