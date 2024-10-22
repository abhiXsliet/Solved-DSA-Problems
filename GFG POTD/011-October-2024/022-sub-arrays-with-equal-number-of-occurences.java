// https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1




//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.HashMap;
// } Driver Code Ends
// User function Template for Java

class Solution {
    // TC : O(N)
    // SC : O(N)
    static int sameOccurrence(int arr[], int x, int y) {
        HashMap<Integer, Integer> mpp = new HashMap<>();
        mpp.put(0, 1);
        int sum   = 0;
        int count = 0;
        
        for (int num : arr) {
            if (num == x) {
                sum ++;
            }
            else if (num == y) {
                sum --;
            }
            
            count += mpp.getOrDefault(sum, 0);
            mpp.put(sum, mpp.getOrDefault(sum, 0) + 1);
        }
        
        return count;
    }
}


//{ Driver Code Starts.
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

            int x = Integer.parseInt(br.readLine());
            int y = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            int ans = ob.sameOccurrence(arr, x, y);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends