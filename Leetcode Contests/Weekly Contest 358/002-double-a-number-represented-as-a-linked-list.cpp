// https://leetcode.com/contest/weekly-contest-358/problems/double-a-number-represented-as-a-linked-list/


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
    vector<int> multiply(vector<int> v){
        vector<int> ans;
        reverse(v.begin(), v.end());
        int carry = 0;
        for(int i=0;i<v.size();i++){
            int sum = carry + (v[i]*2);
            ans.push_back(sum%10);
            carry = sum/10;
        }
        if(carry != 0) ans.push_back(carry);
       return ans;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if(head -> val == 0) {
            return new ListNode(0);
        }
        
        ListNode* temp = head;
        vector<int> store;
        while(temp != NULL) {
            store.push_back(temp->val);
            temp = temp -> next;
        }

        vector<int>newStore = multiply(store);
        
        ListNode* dummy = new ListNode(0);
        ListNode* nodeToInsert = dummy;
        for(int i = newStore.size()-1; i >= 0; i--) {
            nodeToInsert -> next = new ListNode(newStore[i]);
            nodeToInsert = nodeToInsert -> next;
        }
        
        return dummy -> next;
        
    }
};