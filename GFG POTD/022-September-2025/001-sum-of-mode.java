// https://www.geeksforgeeks.org/problems/sum-of-mode/1




import java.util.*;

class Solution {
    // TC : O(N * log(K))
    // SC : O(K)
    public int sumOfModes(int[] arr, int k) {
        int n = arr.length;
        
        Map<Integer, Integer> freq = new HashMap<>();
        TreeMap<Integer, TreeSet<Integer>> freqToVal = new TreeMap<>();
        int i = 0, j = 0, sumModes = 0;
        
        while (j < n) {
            int num = arr[j];
            int oldFreq = freq.getOrDefault(num, 0);
            if (oldFreq > 0) {
                TreeSet<Integer> st = freqToVal.get(oldFreq);
                st.remove(num);
                if (st.isEmpty()) freqToVal.remove(oldFreq);
            }
            
            freq.put(num, oldFreq + 1);
            freqToVal.computeIfAbsent(oldFreq + 1, x -> new TreeSet<>()).add(num);
            
            if (j - i + 1 == k) {
                int maxFreq = freqToVal.lastKey();
                int modes   = freqToVal.get(maxFreq).first();   // smallest no. in the max-freq bucket
                
                sumModes   += modes;
                
                num = arr[i];
                oldFreq = freq.getOrDefault(num, 0);
           
                TreeSet<Integer> st = freqToVal.get(oldFreq);
                st.remove(num);
                if (st.isEmpty()) freqToVal.remove(oldFreq);
                
                if (oldFreq == 1) {
                    freq.remove(num);
                } else {
                    freq.put(num, oldFreq - 1);
                    freqToVal.computeIfAbsent(oldFreq - 1, x -> new TreeSet<>()).add(num);
                }
                
                i ++;
            }
            
            j ++;
        }
        
        return sumModes;
    }
}