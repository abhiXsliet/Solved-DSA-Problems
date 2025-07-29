// https://www.geeksforgeeks.org/problems/ascii-range-sum/1




import java.util.*;

class Solution {
    public ArrayList<Integer> asciirange(String s) {
        int n = s.length();
        int[][] firstOcc = new int[26][2];
        int[][] lastOcc  = new int[26][2];
        
        for (int[] row : firstOcc) Arrays.fill(row, -1);
        for (int[] row : lastOcc) Arrays.fill(row, -1);
        
        int asciiSum = 0;
        List<Integer> uniques = new ArrayList<>();
        
        for (int i = 0; i < n; i ++) {
            int idx = s.charAt(i) - 'a';
            asciiSum += s.charAt(i);
            
            if (firstOcc[idx][0] == -1) {
                firstOcc[idx][0] = i;
                firstOcc[idx][1] = asciiSum;
                uniques.add(idx);
            } else {
                lastOcc[idx][0] = i;
                lastOcc[idx][1] = asciiSum;
            }
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int idx : uniques) {
            int resultantSum = lastOcc[idx][1] - firstOcc[idx][1] - (idx + 'a');
            if (resultantSum > 0) {
                result.add(resultantSum);
            }
        }
        return result;
    }
}