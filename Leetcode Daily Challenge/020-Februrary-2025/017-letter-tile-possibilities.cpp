// https://leetcode.com/problems/letter-tile-possibilities/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N!)
    // SC : O(N) space used by recursive call stack
    void solve_3(vector<int>& freq, int& count) {
        for (int i = 0; i < 26; i ++) {
            if (freq[i] == 0) continue;
            freq[i] --;
            count ++;
            solve_3(freq, count);
            freq[i] ++;
        }
    }

    // TC : O(N!)
    // SC : O(N) space used by recursive call stack
    void solve_2(string &tiles, int n, int idx, string &curr, vector<bool>& vis, int &count) {
        for (int i = 0; i < n; i ++) {
            if (vis[i] || (i > 0 && tiles[i] == tiles[i - 1] && !vis[i - 1])) 
                continue;
            // Mark
            vis[i] = 1;
            curr.push_back(tiles[i]);
            count ++;  

            // Explore
            solve_2(tiles, n, idx + 1, curr, vis, count);
            // Backtrack
            vis[i] = 0;
            curr.pop_back();
        }
    }

    // TC : O(N!) 
    // SC : O(N) space used by recursive call stack
    void solve_1(string &tiles, int n, int idx, string &curr, vector<bool>& vis, unordered_set<string>& seen) {
        seen.insert(curr);  

        for (int i = 0; i < n; i ++) {
            if (vis[i]) continue;
            // Mark
            vis[i] = 1;
            curr.push_back(tiles[i]);
            // Explore
            solve_1(tiles, n, idx + 1, curr, vis, seen);
            // Backtrack
            vis[i] = 0;
            curr.pop_back();
        }
    }

    // TC : O(N!) 
    // SC : O(N! + N) space used by set + string curr
    int approach_1(string tiles) {
        int n = tiles.size();
        vector<bool> visited(n, 0);
        unordered_set<string> seen;
        string curr;
        solve_1(tiles, n, 0, curr, visited, seen);
        return seen.size() - 1; // -1 because "" (empty string) was inserted
    }

    // TC : O(N*log(N) + N!) 
    // SC : O(N) space used by string curr
    int approach_2(string tiles) {
        int n = tiles.size();
        sort(begin(tiles), end(tiles));
        vector<bool> visited(n, 0);
        int count = 0;
        string curr;
        solve_2(tiles, n, 0, curr, visited, count);
        return count; 
    }

    // TC : O(26^N)
    // SC : O(1)
    int approach_3(string tiles) {
        vector<int> freq(26, 0);
        for (char &ch : tiles) {
            freq[ch - 'A'] ++;
        }
        int count = 0;
        solve_3(freq, count);
        return count;
    }
public:
    int numTilePossibilities(string tiles) {
        // return approach_1(tiles);    // used set to avoid duplicate
        // return approach_2(tiles);    // sort tiles and skip duplicate on the go : no set required
        return approach_3(tiles);    // store freq of chars and use it to form the total no. of possible ways
    }
};