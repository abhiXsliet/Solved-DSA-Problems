// https://leetcode.com/problems/minimum-number-of-people-to-teach/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N^2)
    // SC : O(N)
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> cantTalkUsers;   // these users can't communicate with each other due to language barrier b/w them

        for (vector<int> friendship : friendships) {
            int u = friendship[0] - 1;
            int v = friendship[1] - 1;
            
            unordered_set<int> st(begin(languages[u]), end(languages[u]));
            
            bool canTalk = false;
            for (int lang : languages[v]) {
                if (st.count(lang)) {
                    canTalk = true;
                    break;
                }
            }

            if (!canTalk) {
                cantTalkUsers.insert(u);
                cantTalkUsers.insert(v);
            }
        }

        vector<int> langFreq(n + 1, 0);
        int mostKnownLangFreq = 0;

        for (int user : cantTalkUsers) {
            for (int lang : languages[user]) {
                langFreq[lang] ++;
                mostKnownLangFreq = max(mostKnownLangFreq, langFreq[lang]);
            } 
        }

        return cantTalkUsers.size() - mostKnownLangFreq;
    }
};