// https://leetcode.com/problems/valid-word/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public boolean isValid(String word) {
        int n = word.length();
        if (n < 3) return false;
        boolean vowel = false, consonant = false;
        for (char ch : word.toCharArray()) {
            ch = Character.toLowerCase(ch);
            if (!isValid(ch)) return false;
            else {
                if (isVowel(ch)) vowel = true;
                else if (!Character.isDigit(ch)) consonant = true;
            }
        }
        return (vowel && consonant);
    }
    private boolean isValid(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
    }
    private boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
}