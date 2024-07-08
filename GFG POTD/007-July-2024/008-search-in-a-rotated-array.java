// https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1



//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String line = in.readLine();
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

            int key = Integer.parseInt(in.readLine().trim());

            out.println(new Solution().search(arr, key));
        }
        out.close();
    }
}
// } Driver Code Ends

// User function Template for Java
class Solution {
    // TC : O(log(N)) Where N = Length of array
    // SC : O(1)
    int search(int[] arr, int key) {
        int n = arr.length;
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if (arr[mid] == key) return mid;
            // check which part is sorted
            if (arr[low] <= arr[mid]) { // left part is sorted
                if (key >= arr[low] && key <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low  = mid + 1;
                }
            } else {    // right part is sorted
                if (key >= arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
}