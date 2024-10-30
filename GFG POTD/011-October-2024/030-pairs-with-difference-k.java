// https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1




//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
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

            int k = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            int ans = ob.countPairsWithDiffK(arr, k);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends

// User function Template for Java
class Solution {
    // TC : O(N)
    // SC : O(N)
    int countPairsWithDiffK(int[] arr, int k) {
        HashMap<Integer, Integer> mpp = new HashMap<>();
        int cntPairs = 0;
        for (int num : arr) {
            cntPairs += mpp.getOrDefault(num + k, 0); 
            cntPairs += mpp.getOrDefault(num - k, 0); 
            
            mpp.put(num, mpp.getOrDefault(num, 0) + 1);
        }
        return cntPairs;
    }
}