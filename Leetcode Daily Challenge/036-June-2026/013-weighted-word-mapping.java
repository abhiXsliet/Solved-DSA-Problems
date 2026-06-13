// https://leetcode.com/problems/weighted-word-mapping/




class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder result = new StringBuilder();

        for (String word : words) {
            int sum = 0;

            for (char ch : word.toCharArray()) {
                sum += weights[ch - 'a'];
            }

            sum %= 26;

            result.append((char)('z' - sum));
        }

        return result.toString();
    }
}