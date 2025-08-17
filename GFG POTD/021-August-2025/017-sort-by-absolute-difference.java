// https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1




import java.util.*;

class Solution {
    public void rearrange(int[] arr, int x) {
        // way_1(arr, x);
        way_2(arr, x);
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    private void way_2(int[] arr, int x) {
        
        // boxing primitive data type int to object for using Arrays.sort() for stable sorting
        Integer[] boxed = Arrays.stream(arr).boxed().toArray(Integer[]::new);    
        
        Arrays.sort(boxed, (a, b) -> {
            int d1 = Math.abs(a - x);
            int d2 = Math.abs(b - x);
            return Integer.compare(d1, d2); // stable sort will maintain original order for equal distances
        });
        
        for (int i = 0; i < arr.length; i ++) {
            arr[i] = boxed[i];
        }
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    private void way_1(int[] arr, int x) {
        List<Integer> list = new ArrayList<>();
        for (int val : arr) list.add(val);
        
        // Collections.sort is stable (uses Timsort internally)
        Collections.sort(list, (a, b) -> {
            int d1 = Math.abs(a - x);
            int d2 = Math.abs(b - x);
            return Integer.compare(d1, d2); 
        });
        
        for (int i = 0; i < arr.length; i ++) {
            arr[i] = list.get(i);
        }
    }
}