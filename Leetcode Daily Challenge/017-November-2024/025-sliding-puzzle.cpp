// www.leetcode.com/problems/sliding-puzzle/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(6!) = 720
    // SC : O(6!) all states get stored in map at worst
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 3; j ++) {
                start += to_string(board[i][j]);
            }
        }

        string target = "123450";

        queue<string> que;
        unordered_set<string> visited;
        que.push(start);
        visited.insert(start);

        // stores the respectives indices from which zero can be swapped
        unordered_map<int, vector<int>> mpp;    
        mpp[0] = {1, 3};
        mpp[1] = {0, 2, 4};
        mpp[2] = {1, 5};
        mpp[3] = {0, 4};
        mpp[4] = {1, 3, 5};
        mpp[5] = {2, 4};

        int level = 0;
        while (!que.empty()) {
            int n = que.size();
            while (n --) {
                string topState = que.front();
                que.pop();

                if (topState == target) {
                    return level;
                }

                int idxZero = topState.find('0');

                for (int idxSwap : mpp[idxZero]) {
                    string currState = topState;
                    swap(currState[idxSwap], currState[idxZero]);
                    if (!visited.count(currState)) {
                        que.push(currState);
                        visited.insert(currState);
                    }
                }
            }
            level ++;
        }

        return -1;
    }
};