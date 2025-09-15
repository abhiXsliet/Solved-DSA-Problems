// Leetcode Daily Challenge/027-September-2025/015-maximum-number-of-words-you-can-type.cpp/




import java.util.*;

class Solution {
    // TC : O(M + N)
    // SC : O(1)
    public int canBeTypedWords(String text, String brokenLetters) {
        int[] brokenFreq = new int[26];
        for (char ch : brokenLetters.toCharArray()) {
            if (brokenFreq[ch - 'a'] == 0) {
                brokenFreq[ch - 'a'] = 1;
            }
        }

        boolean isBroken = false;
        int result = 0;

        for (char ch : text.toCharArray()) {
            if (ch == ' ') {
                if (isBroken == false) {
                    result += 1;
                }
                isBroken = false;
            } else if (brokenFreq[ch - 'a'] == 1) {
                isBroken = true;
            }
        }

        if (isBroken == false) result += 1;

        return result;
    }
}