// https://leetcode.com/problems/minimum-number-of-people-to-teach/




import java.util.*;

class Solution {
    // TC : O(N^2)
    // SC : O(N)
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer> cantTalkUsers = new HashSet<>();

        for (int[] friendship : friendships) {
            int u = friendship[0] - 1;
            int v = friendship[1] - 1;

            Set<Integer> st = new HashSet<>();
            for (int lang : languages[u]) {
                st.add(lang);
            }

            boolean canTalk = false;
            for (int lang : languages[v]) {
                if (st.contains(lang)) {
                    canTalk = true;
                    break;
                }
            }

            if (canTalk == false) {
                cantTalkUsers.add(u);
                cantTalkUsers.add(v);
            }
        }

        int[] langFreq = new int[n + 1];
        int mostKnownLangFreq = 0;

        for (int user : cantTalkUsers) {
            for (int lang : languages[user]) {
                langFreq[lang] += 1;
                mostKnownLangFreq = Math.max(mostKnownLangFreq, langFreq[lang]);
            }
        }

        return cantTalkUsers.size() - mostKnownLangFreq;
    }
}