// https://www.geeksforgeeks.org/problems/choose-and-swap0531/1/




import java.util.*;

class Solution {
    public String chooseSwap(String s) {
        int n = s.length();
        
        int[] freq = new int[26];
        Arrays.fill(freq, -1);
        
        // store first occurrence
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            if (freq[idx] == -1) {
                freq[idx] = i; 
            }
        }
        
        char[] arr = s.toCharArray();
        
        for (int i = 0; i < n; i++) {
            int curr = arr[i] - 'a';
            
            for (int ch = 0; ch < curr; ch++) {
                if (freq[ch] > i) {
                    char ch1 = arr[i];
                    char ch2 = (char)(ch + 'a');
                    
                    // swap all occurrences
                    for (int j = 0; j < n; j++) {
                        if (arr[j] == ch1) {
                            arr[j] = ch2;
                        } else if (arr[j] == ch2) {
                            arr[j] = ch1;
                        }
                    }
                    
                    return new String(arr);
                }
            }
        }
        
        return s;
    }
}