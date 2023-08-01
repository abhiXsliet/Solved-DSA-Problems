// https://leetcode.com/problems/combinations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC = O(C(n, k)), where C(n, k) represents the number of combinations of 'n' items taken 'k' at a time.
    // SC = O(k) on the stack due to the recursive calls 
    void solveRec(int& n, int k, int start, vector<int>& temp, vector<vector<int>>& ans) {
        if(k == 0) {
            ans.push_back(temp);
        }

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solveRec(n, k-1, i+1, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solveRec(n, k, 1, temp, ans);
        return ans;
    }
};



// Way-2 of writting code without loop
class Solution {
    // TC = O(C(n, k)), where C(n, k) represents the number of combinations of 'n' items taken 'k' at a time.
    // SC = O(k) on the stack due to the recursive calls 
    void solveRec(int& n, int k, int start, vector<int>& temp, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(temp);
            return;
        }

        if (start > n) return;

        temp.push_back(start);
        solveRec(n, k-1, start+1, temp, ans);
        
        temp.pop_back();
        solveRec(n, k, start+1, temp, ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solveRec(n, k, 1, temp, ans);
        return ans;
    }
};