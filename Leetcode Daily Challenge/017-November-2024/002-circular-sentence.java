// https://leetcode.com/problems/circular-sentence/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(N)
    public boolean isCircularSentence(String sentence) {
        int n = sentence.length();
        if (sentence.charAt(0) != sentence.charAt(n - 1))
            return false;

        Scanner scanner = new Scanner(sentence);
        char prev = '$';

        while (scanner.hasNext()) {
            String word = scanner.next();
            int len = word.length();
            if (prev == '$') {
                prev = word.charAt(len - 1);
            } else {
                if (prev != word.charAt(0)) {
                    return false;
                } else {
                    prev = word.charAt(len - 1);
                }
            }
        }   

        scanner.close();
        return true;
    }
}