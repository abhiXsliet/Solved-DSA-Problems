// https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1




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

            v = new Solution().removeDuplicate(arr);

            for (int i = 0; i < v.size(); i++) System.out.print(v.get(i) + " ");

            System.out.println();
        
            System.out.println("~");
        }
    }
}

// } Driver Code Ends
class Solution {
    // TC : O(N)
    // SC : O(1)
    ArrayList<Integer> removeDuplicate(int arr[]) {
        ArrayList<Integer> ans  = new ArrayList<>();
        ArrayList<Integer> freq = new ArrayList<>();
        for (int i = 0; i < 101; i ++) {
            freq.add(0);
        }
        for (int num : arr) {
            if (freq.get(num) == 0) {
                ans.add(num);
                freq.set(num, 1);
            }
        }
        return ans;
    }
}