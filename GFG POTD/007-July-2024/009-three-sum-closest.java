// https://www.geeksforgeeks.org/problems/three-sum-closest/1



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

            out.println(new Solution().threeSumClosest(arr, key));
        }
        out.close();
    }
}
// } Driver Code Ends

// User function Template for Java
class Solution {
    // TC : O(N^2)
    // SC : O(1)
    static int threeSumClosest(int[] arr, int target) {
        Arrays.sort(arr);
        
        int n          = arr.length;
        int closestSum = Integer.MAX_VALUE;
        int minDiff    = Integer.MAX_VALUE;
        
        for (int i = 0; i < n - 2; ++i) {
            int low  = i + 1;
            int high = n - 1;
            
            while (low < high) {
                int currentSum = arr[i] + arr[low] + arr[high];
                int currentDiff = Math.abs(currentSum - target);
                
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                } else if (currentDiff == minDiff) {
                    closestSum = Math.max(closestSum, currentSum);
                }
                
                if (currentSum < target) {
                    ++low;
                } else {
                    --high;
                }
            }
        }
        
        return closestSum;
    }
}