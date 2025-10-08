// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(int potion, int spell, long long success) {
        return (spell * (long long)potion) >= success;
    }

    int getSuccessfulPair(vector<int> &arr, int spell, long long success) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr[mid], spell, success)) {
                ans = (n - mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // TC : O(N * log(M))
    // SC : O(1)
    vector<int> approach_1(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size(), m = potions.size();

        sort(begin(potions), end(potions));

        vector<int> result(n, 0);
        for (int i = 0; i < n; i ++) {
            result[i] = getSuccessfulPair(potions, spells[i], success);
        }
        return result;
    }

    // TC : O(N*log(N) + M*log(M))
    // SC : O(1)
    vector<int> approach_2(vector<int> &spells, vector<int> &potions, long long success) {
        int n = spells.size(), m = potions.size();

        vector<pair<int, int>> storeSpells(n);
        for (int i = 0; i < n; i ++) {
            storeSpells[i] = {spells[i], i};
        }

        sort(rbegin(storeSpells), rend(storeSpells));
        sort(begin(potions), end(potions));
        int j = 0;

        vector<int> result(n, 0);
        for (int i = 0; i < n; i ++) {
            int spell = storeSpells[i].first;
            int spellIdx = storeSpells[i].second;

            while ((j < m) && ((long long)spell * potions[j]) < success) j ++;
            
            result[spellIdx] = (m - j);
        }
        return result;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // return approach_1(spells, potions, success); // bs
        return approach_2(spells, potions, success); // two pointer      
    }
};