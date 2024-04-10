// https://leetcode.com/problems/reveal-cards-in-increasing-order/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N)) + O(N*log(N))
    // SC : O(1)
    vector<int> approach_1(vector<int>& deck) {
        int n = deck.size();
        vector<int> result(n, 0);
        
        int i = 0;  // for deck
        int j = 0;  // for result
        bool skip = 0;

        sort(begin(deck), end(deck));

        while(i < n) {
            if (result[j] == 0) {
                if (skip == false) {
                    result[j] = deck[i];
                    i ++;
                }
                skip = !skip;
            }
            j = (j + 1) % n;
        }
        return result;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_2(vector<int>& deck) {
        int n = deck.size();
        vector<int> result(n, 0);
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        sort(begin(deck), end(deck));

        for (int i = 0; i < n; i++) {
            int idx = q.front();
            q.pop();

            result[idx] = deck[i];

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // return approach_1(deck);

        return approach_2(deck);
    }
};