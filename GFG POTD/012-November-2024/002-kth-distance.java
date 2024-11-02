// https://www.geeksforgeeks.org/problems/kth-distance3757/1



//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    // TC : O(N)
    // SC : O(K)
    public boolean checkDuplicatesWithinK(int[] arr, int k) {
        int n = arr.length;
        HashMap<Integer, Integer> mpp = new HashMap<>();
        int i = 0;
        int j = 0;
        while (j < n) {
            mpp.put(arr[j], mpp.getOrDefault(arr[j], 0) + 1);
            if (mpp.get(arr[j]) == 2) 
                return true;
            if (j - i == k) {
                mpp.put(arr[i], mpp.get(arr[i]) - 1);
                if (mpp.get(arr[i]) == 0)  
                    mpp.remove(arr[i]);
                i ++;
            }
            j ++;
        }
        return false;
    }
}

//{ Driver Code Starts.

class GFG {
    public static void main(String[] args) throws IOException {
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
            int k = Integer.parseInt(br.readLine());
            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;
            Solution obj = new Solution();
            boolean res = obj.checkDuplicatesWithinK(arr, k);
            if (res)
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}
// } Driver Code Ends