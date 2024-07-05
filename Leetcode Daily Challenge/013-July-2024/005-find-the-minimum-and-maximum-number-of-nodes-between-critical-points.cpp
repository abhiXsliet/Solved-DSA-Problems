// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void getMinimaMaxima(ListNode* head, vector<int>& store) {
        int cnt = 2;
        while(head -> next -> next) {
            if (head -> next -> val < head -> val && head -> next -> val < head -> next -> next -> val) {
                store.push_back(cnt);
            } else if (head -> next -> val > head -> val && head -> next -> val > head -> next -> next -> val) {
                store.push_back(cnt);
            }
            head = head -> next;
            cnt += 1;
        }
    }
    
    // TC : O(N*N)
    // SC : O(N)  where N = No. of Nodes in given LL
    vector<int> brute(ListNode* head) {
        if (!head -> next -> next) return {-1, -1};
        
        vector<int> store;
        getMinimaMaxima(head, store);
        sort(begin(store), end(store));
       
        int minima = INT_MAX;
        int maxima = INT_MIN;
        int n = store.size();

        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                if (i == j) continue;
                minima = min(minima, abs(store[i] - store[j]));
                maxima = max(maxima, abs(store[i] - store[j]));
            }
        }
        if (minima != INT_MAX && maxima != INT_MIN) 
            return {minima, maxima};
        return {-1, -1};
    }

    // TC : O(N) Where N = No. of Nodes
    // SC : O(1)
    vector<int> optimal(ListNode* head) {    
        int firstCriticalPt = 0;
        int prevCriticalPt  = 0;
        int countOfNodes    = 2;
        int minima          = INT_MAX;
        
        while (head -> next -> next) {
            if (head -> next -> val < head -> val && head -> next -> val < head -> next -> next -> val || 
                head -> next -> val > head -> val && head -> next -> val > head -> next -> next -> val) {
                
                if (firstCriticalPt == 0) {
                    firstCriticalPt = countOfNodes;
                    prevCriticalPt  = countOfNodes;
                } else {
                    minima = min(minima, countOfNodes - prevCriticalPt);
                    prevCriticalPt = countOfNodes;
                }
            } 
            head = head -> next;
            countOfNodes += 1;
        }

        if (minima == INT_MAX) 
            return {-1, -1};

        int maxima = prevCriticalPt - firstCriticalPt;
        return {minima, maxima};
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // return brute(head);

        return optimal(head);
    }
};