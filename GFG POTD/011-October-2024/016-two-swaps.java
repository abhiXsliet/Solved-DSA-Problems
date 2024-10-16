// https://www.geeksforgeeks.org/problems/two-swaps--155623/1




//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine()); // Read number of test cases

        // Loop through each test case
        while (t-- > 0) {
            String input = scanner.nextLine();
            String[] inputArr = input.split(" ");
            List<Integer> arr = new ArrayList<>();

            // Convert input to list of integers
            for (String str : inputArr) {
                arr.add(Integer.parseInt(str));
            }

            Solution ob = new Solution();
            boolean ans = ob.checkSorted(arr);

            // Output result
            if (ans)
                System.out.println("true");
            else
                System.out.println("false");
        }

        scanner.close();
    }
}

// } Driver Code Ends
class Solution {
    public boolean checkSorted(List<Integer> arr) {
        int n = arr.size();
        int cntSwaps = 0;
        for (int i = 0; i < n; i ++) {
            if (arr.get(i) - 1 != i) {
                Collections.swap(arr, i, arr.get(i) - 1);
                cntSwaps ++;
                i --;
            }
        }
        return true ? cntSwaps == 0 || cntSwaps == 2 : false;
    }
}
