// https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    int countStrings(String s) {
        int n = s.length();
        List<Integer> freq = new ArrayList<>(Collections.nCopies(26, 0));
        
        for (char ch : s.toCharArray()) {
            int idx = ch - 'a';
            freq.set(idx, freq.get(idx) + 1);
        }
        
        int totalSwaps = n * (n - 1) / 2;
        int noEffectSwaps = 0;
        
        for (int f : freq) {
            noEffectSwaps += f * (f - 1) / 2;
        }
        
        int extraOne = (noEffectSwaps == 0) ? 0 : 1;
        return (totalSwaps - noEffectSwaps) + extraOne;
    }
}