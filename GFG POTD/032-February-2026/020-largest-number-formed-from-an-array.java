// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1/




import java.util.*;

class Solution {
    public String findLargest(int[] arr) {
        int n = arr.length;
        
        String[] nums = new String[n];
        for (int i = 0; i < n; i ++) {
            nums[i] = String.valueOf(arr[i]);
        }
        
        Arrays.sort(nums, (a, b) -> (b + a).compareTo(a + b));
        
        if (nums[0].equals("0")) return "0";
        
        StringBuilder largestNum = new StringBuilder();
        for (String num : nums) {
            largestNum.append(num);
        }
        return largestNum.toString();
    }
}