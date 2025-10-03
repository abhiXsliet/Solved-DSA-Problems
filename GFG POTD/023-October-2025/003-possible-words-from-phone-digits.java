// https://www.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/




import java.util.*;

class Solution {
    /*
        Time Complexity      : O(n * 4^n)
        Auxiliary Space      : O(n)
        Recursive Stack Space: O(n)
    */
    public ArrayList<String> possibleWords(int[] arr) {
        Map<Integer, String> mpp = new HashMap<>();
        mpp.put(1, "");
        mpp.put(0, "");
        mpp.put(2, "abc");
        mpp.put(3, "def");
        mpp.put(4, "ghi");
        mpp.put(5, "jkl");
        mpp.put(6, "mno");
        mpp.put(7, "pqrs");
        mpp.put(8, "tuv");
        mpp.put(9, "wxyz");

        ArrayList<String> result = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        solve(arr, 0, temp, result, mpp);
        return result;
    }
    private static void solve(int[] arr, int idx, StringBuilder temp, ArrayList<String> result, Map<Integer, String> mpp) {
        if (idx >= arr.length) {
            result.add(temp.toString());
            return;
        }
        
        String str = mpp.get(arr[idx]);
        if (str.isEmpty()) {
            solve(arr, idx + 1, temp, result, mpp);
        } else {
            for (char ch : str.toCharArray()) {
                temp.append(ch);
                solve(arr, idx + 1, temp, result, mpp);
                temp.deleteCharAt(temp.length() - 1);
            }
        }
    }
}