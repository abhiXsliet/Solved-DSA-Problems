// https://www.geeksforgeeks.org/problems/balancing-consonants-and-vowels-ratio/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public int countBalanced(String[] arr) {
        Map<Integer, Integer> mpp = new HashMap<>();
        mpp.put(0, 1);
        int result = 0, balance = 0;
        for (String str : arr) {
            int v = 0, c = 0;
            for (char ch : str.toCharArray()) {
                if (isVowel(ch)) v ++;
                else c ++;
            }
            
            balance += (v - c);
            result += mpp.getOrDefault(balance, 0);
            mpp.put(balance, mpp.getOrDefault(balance, 0) + 1);
        }
        return result;
    }
    private boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
}