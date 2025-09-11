// https://leetcode.com/problems/sort-vowels-in-a-string/




import java.util.*;

class Solution {
    public String sortVowels(String s) {
        // return approach_1(s);
        return approach_2(s);
    }

    // TC : O(N)
    // SC : O(1)
    private static String approach_2(String s) {
        Map<Character, Integer> mpp = new HashMap<>();
        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) 
                mpp.put(ch, mpp.getOrDefault(ch, 0) + 1);
        }

        String vowels = "AEIOUaeiou";
        StringBuilder result = new StringBuilder();
        int j = 0;

        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                while (j < vowels.length() && mpp.getOrDefault(vowels.charAt(j), 0) == 0) {
                    j ++;
                }
                char replace = vowels.charAt(j);
                result.append(replace);
                mpp.put(replace, mpp.get(replace) - 1);
            } else {
                result.append(ch);
            }
        }

        return result.toString();
    }

    // TC : O(N*log(N))
    // SC : O(N)
    private static String approach_1(String s) {
        List<Character> vowels = new ArrayList<>();
        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                vowels.add(ch);
            }
        }

        vowels.sort(Comparator.naturalOrder());

        StringBuilder t = new StringBuilder();
        int j = 0;

        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                t.append(vowels.get(j ++));
            } else {
                t.append(ch);
            }
        }

        return t.toString();
    }

    private static boolean isVowel(char ch) {
        ch = Character.toLowerCase(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
}