// https://www.geeksforgeeks.org/problems/reorganize-the-array4810/1



//{ Driver Code Starts
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
// } Driver Code Ends

class Solution {
    // TC : O(N)
    // SC : O(1)
    public List<Integer> rearrange(List<Integer> arr) {
        int n = arr.size();
        List<Integer> res = new ArrayList<>();
        for (int i = 0 ; i < n; i ++) {
            res.add(-1);
        }
        
        for (int i = 0; i < n; i ++) {
            int num = arr.get(i);
            if (num != -1 && num < n) {
                res.set(num, num);
            }
        }
        return res;
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        Solution solution = new Solution();

        while (t-- > 0) {
            String input = scanner.nextLine();
            String[] inputArr = input.split("\\s+");
            List<Integer> arr = new ArrayList<>();
            for (String s : inputArr) {
                arr.add(Integer.parseInt(s));
            }

            List<Integer> ans = solution.rearrange(arr);

            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
        }

        scanner.close();
    }
}
// } Driver Code Ends