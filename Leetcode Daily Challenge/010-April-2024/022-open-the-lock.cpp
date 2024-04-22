// https://leetcode.com/problems/open-the-lock/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(1)
    // SC : O(1)
    void visitNeighbourNodes(string& curr, queue<string>& q, unordered_set<string>& st) {
        for (int i = 0; i < 4; i++) {
            char ch = curr[i];

            char dec = ch == '0' ? '9' : ch - 1;
            char inc = ch == '9' ? '1' : ch + 1;

            curr[i] = dec;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                q.push(curr);
            }

            curr[i] = inc;
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                q.push(curr);
            }

            curr[i] = ch;
        }
    }
public:
    // TC : O(N^W)
    // SC : O(N^W)
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        queue<string> q;
        unordered_set<string> st(begin(deadends), end(deadends));
        
        if (st.find(start) != st.end()) 
            return -1;

        q.push(start);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            while(n--) {
                string curr = q.front(); 
                q.pop();

                if (curr == target) 
                    return level;

                visitNeighbourNodes(curr, q, st);   
            }
            level ++;
        }
        return -1;
    }
};