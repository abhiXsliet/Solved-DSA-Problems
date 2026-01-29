// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1/




class Solution {
    public String firstNonRepeating(String s) {
        // return approach_1(s);
        return approach_2(s);
    }
    
    // TC : O(N)
    // SC : O(1)
    private static String approach_2(String s) {
        int n = s.length();
        
        int[] freq = new int[26];
        int[] initial = new int[26];
        Arrays.fill(initial, -1);
        
        for (int i = 0; i < n; i ++) {
            if (initial[s.charAt(i) - 'a'] == -1) {
                initial[s.charAt(i) - 'a'] = i;
            }
        }
        
        StringBuilder result = new StringBuilder();
        
        for (int i = 0; i < n; i ++) {
            freq[s.charAt(i) - 'a'] ++;
            
            char req = '#';
            int count = n + 1;
            
            for (int j = 0; j < 26; j ++) {
                if (freq[j] == 1 && count > initial[j]) {
                    count = initial[j];
                    req = (char) (j + 'a');
                }
            }
            
            result.append(req);
        }
        
        return result.toString();
    }

    // TC : O(N)
    // SC : O(N)
    private static String approach_1(String s) {
        int[] freq = new int[26];
        Queue<Character> q = new LinkedList<>();
        StringBuilder result = new StringBuilder();
        
        for (char ch : s.toCharArray()) {
            q.offer(ch);
            freq[ch - 'a'] ++;
            
            while (!q.isEmpty()) {
                if (freq[q.peek() - 'a'] > 1) {
                    q.poll();
                } else {
                    result.append(q.peek());
                    break;
                }
            }
            
            if (q.isEmpty()) result.append('#');
        }
        
        return result.toString();
    }
}