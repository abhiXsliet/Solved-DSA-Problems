// https://leetcode.com/problems/spiral-matrix-iv/



#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // TC : O(M * N)
    // SC : O(1)
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));

        int startRow = 0;
        int startCol = 0;
        int endRow   = m - 1;
        int endCol   = n - 1;
        ListNode* curr = head;
        
        while (curr) {
            for (int j = startCol; curr && j <= endCol; j ++) {
                result[startRow][j] = curr -> val;
                curr = curr -> next;
            }
            startRow ++;

            for (int i = startRow; curr && i <= endRow; i ++) {
                result[i][endCol] = curr -> val;
                curr = curr -> next;
            }
            endCol --;

            for (int j = endCol; curr && j >= startCol; j --) {
                result[endRow][j] = curr -> val;
                curr = curr -> next;
            }
            endRow --;

            for (int i = endRow; curr && i >= startRow; i --) {
                result[i][startCol] = curr -> val;
                curr = curr -> next;
            }
            startCol ++;
        }
        return result;
    }
};