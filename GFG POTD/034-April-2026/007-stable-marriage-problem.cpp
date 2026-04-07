// https://www.geeksforgeeks.org/problems/stable-marriage-problem/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<int> womenPartner(n, -1);    // woman -> man
        vector<int> menPartner(n, -1);      // men -> women
        vector<int> nextProposal(n, 0);     // men next proposal women index
        
        // ranked men a/c to women perspective
        vector<vector<int>> ranks(n, vector<int>(n));
        for (int w = 0; w < n; w ++) {
            for (int rank = 0; rank < n; rank ++) {
                ranks[w][women[w][rank]] = rank;
            }
        }
        
        queue<int> freeMen;
        for (int m = 0; m < n; m ++) freeMen.push(m);
        
        while (!freeMen.empty()) {
            int man = freeMen.front();
            freeMen.pop();
            
            int woman = men[man][nextProposal[man]];
            nextProposal[man] ++;
            
            if (womenPartner[woman] == -1) {
                womenPartner[woman] = man;
                menPartner[man] = woman;
            } else {
                int currMan = womenPartner[woman];
                
                if (ranks[woman][man] < ranks[woman][currMan]) {
                    womenPartner[woman] = man;
                    menPartner[man] = woman;
                    
                    freeMen.push(currMan);
                    menPartner[currMan] = -1;
                } else {
                    freeMen.push(man);
                }
            }
        }
        
        return menPartner;
    }
};