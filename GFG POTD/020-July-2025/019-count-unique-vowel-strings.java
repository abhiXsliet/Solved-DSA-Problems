// https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public int vowelCount(String s) {
        Map<Character, Integer> mpp = new HashMap<>();
        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                mpp.put(ch, mpp.getOrDefault(ch, 0) + 1);
            }
        }
        
        long ans = (mpp.size() > 0) ? getFactorial(mpp.size()) : 0;
        for (Map.Entry<Character, Integer>it : mpp.entrySet()) {
            ans *= it.getValue();
        }
        return (int)ans;
    }
    private boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    private long getFactorial(int n) {
        long ans = 1;
        for (int i = n; i >= 1; i --) {
            ans *= i;
        }
        return ans;
    }
}